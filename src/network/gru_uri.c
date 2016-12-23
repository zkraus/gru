/**
 Copyright 2016 Otavio Rodolfo Piske

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */
#include "gru_uri.h"
#include "common/gru_alloc.h"

static inline size_t gru_uri_calc_buffer_size(UriTextRangeA *range) {
	if (!range || !range->first) {
		return 0;
	}

	if (range->afterLast) {
		return range->afterLast - range->first;
	} else {
		return strlen(range->first);
	}
}

static char *gru_uri_get_ranged_data(UriTextRangeA *range, gru_status_t *status)
{
	size_t len = gru_uri_calc_buffer_size(range);

	size_t buff_size = len + 1;
	char *ret = gru_alloc(buff_size, status);
	gru_alloc_check(ret, NULL);

	strlcpy(ret, range->first, buff_size);

	return ret;
}

static uint16_t gru_uri_get_port(UriTextRangeA *range, gru_status_t *status) {
	uint16_t ret = 0;

	const char *port = gru_uri_get_ranged_data(range, status);

	if (!port || (status->code != GRU_SUCCESS)) {
		return 0;
	}

	ret = atoi(port);
	gru_dealloc_const_string(&port);

	return ret;
}

/**
 * Calculate the required buffer size for storing the whole path taking into account the
 * path separator
 * @param uri
 * @return
 */
static size_t gru_uri_calc_path_size(UriUriA *uri) {
	size_t total = 1; // starts /w 1 for the initial /
	UriPathSegmentA *cur = uri->pathHead;

	while (cur) {
		// Adds + 1 for the '/' path separator
		total += gru_uri_calc_buffer_size(&cur->text) + 1;

		cur = cur->next;
	}

	return total;
}


static char *gru_uri_path(UriUriA *gru_restrict uri, gru_status_t *gru_restrict status)
{
	size_t total = gru_uri_calc_path_size(uri);

	char *ret = gru_alloc(total, status);
	gru_alloc_check(ret, NULL);

	UriPathSegmentA *cur = uri->pathHead;
	while (cur) {
		const char *cur_path = gru_uri_get_ranged_data(&cur->text, status);
		if (!cur_path) {
			gru_dealloc_string(&ret);

			return NULL;
		}

		strlcat(ret, "/", total);
		strlcat(ret, cur_path, total);

		gru_dealloc_const_string(&cur_path);

		cur = cur->next;
	}

	return ret;
}


gru_uri_t gru_uri_parse(const char *url, gru_status_t *status) {
	gru_uri_t ret = {0};
	UriParserStateA state;
	UriUriA uri;

	state.uri = &uri;
	if (uriParseUriA(&state, url) != URI_SUCCESS) {
		uriFreeUriMembersA(&uri);
		gru_status_set(status, GRU_FAILURE, "Unable to parse URL %s", url);

		return ret;
	}

	ret.host = gru_uri_get_ranged_data(&uri.hostText, status);
	ret.port = gru_uri_get_port(&uri.portText, status);
	ret.path = gru_uri_path(&uri, status);
	ret.scheme = gru_uri_get_ranged_data(&uri.scheme , status);

	uriFreeUriMembersA(&uri);

	return ret;
}


void gru_uri_cleanup(gru_uri_t *uri) {
	gru_dealloc_string(&uri->host);
	gru_dealloc_string(&uri->path);
	gru_dealloc_string(&uri->scheme);
}