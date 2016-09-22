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

#ifndef GRU_CONFIG_H
#define GRU_CONFIG_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <pthread.h>
#include <inttypes.h>
#include <assert.h>

#include "common/gru_base.h"
#include "string/gru_util.h"
#include "io/gru_path.h"
#include "io/gru_ioutils.h"

#include "gru_payload.h"

#ifdef __cplusplus
extern "C" {
#endif
    

    
typedef struct gru_config_t_ {
    char *dir;
    char *filename;
    FILE *file;
    
    gru_payload_t *payload;
} gru_config_t;


gru_config_t *gru_config_init(const char *dir, const char *filename, 
                              gru_payload_t *payload, gru_status_t *status);

void gru_config_destroy(gru_config_t **config);

void gru_config_set(char *dest, uint32_t size, const char *fmt, ...);

void gru_config_read(const char *name, FILE *source, void *dest, const char *mask);

void gru_config_read_string(const char *name, FILE *source, char *dest);
void gru_config_read_short(const char *name, FILE *source, int16_t *dest);
void gru_config_read_ushort(const char *name, FILE *source, uint16_t *dest);
void gru_config_read_int(const char *name, FILE *source, int32_t *dest);
void gru_config_read_uint(const char *name, FILE *source, uint32_t *dest);
void gru_config_read_long(const char *name, FILE *source, int64_t *dest);
void gru_config_read_ulong(const char *name, FILE *source, uint64_t *dest);

void gru_config_write_short(const char *name, FILE *dest, int16_t value);
void gru_config_write_ushort(const char *name, FILE *dest, uint16_t value);
void gru_config_write_int(const char *name, FILE *dest, int32_t value);
void gru_config_write_uint(const char *name, FILE *dest, uint32_t value);
void gru_config_write_long(const char *name, FILE *dest, int64_t value);
void gru_config_write_ulong(const char *name, FILE *dest, uint64_t value);

void gru_config_write_string(const char *name, FILE *dest, const char *value);

#ifdef __cplusplus
}
#endif

#endif /* GRU_CONFIG_H */

