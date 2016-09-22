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
#include "gru_time_utils.h"


void gru_time_add_seconds(struct timeval *t, uint64_t count) {
    t->tv_sec = t->tv_sec + count;
}


void gru_time_add_minutes(struct timeval *t, uint64_t count) {
    gru_time_add_seconds(t, (count *60));
}
