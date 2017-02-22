/*
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
#ifndef GRU_DURATION_H
#define GRU_DURATION_H

#include <math.h>
#include <stdlib.h>

#if !defined(_WIN32) && !defined(_WIN64)
#include <sys/time.h>
#else
#include <windows.h>
#endif

#include "common/gru_portable.h"
#include "gru_time_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct gru_duration_t_ {
	struct timeval start;
	struct timeval end;
} gru_duration_t;

/**
 * Builds a duration struct that represents a duration. That means, the current time + 
 * the given number of seconds
 * @param seconds the duration in seconds
 * @return a duration object
 */
gru_export gru_duration_t gru_duration_from_seconds(uint64_t seconds);

/**
 * Builds a duration struct that represents a duration. That means, the current time + 
 * the given number of minutes
 * @param minutes the duration in minutes
 * @return a duration object
 */
gru_export gru_duration_t gru_duration_from_minutes(uint64_t minutes);

/**
 * Given a duration object, return the number of seconds between its start and end 
 * time
 * @param duration a duration object to calculate
 * @return the time difference in seconds
 */
gru_export uint64_t gru_duration_seconds(gru_duration_t duration);

/**
 * Given a duration object, return the number of minutes between its start and end 
 * time
 * @param duration a duration object to calculate
 * @return the time difference in minutes
 */
gru_export uint64_t gru_duration_minutes(gru_duration_t duration, double *fractional);

#ifdef __cplusplus
}
#endif

#endif /* GRU_DURATION_H */
