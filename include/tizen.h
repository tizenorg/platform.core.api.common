/*
 * Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. 
 */
#ifndef __TIZEN_H__
#define __TIZEN_H__

#include <tizen_type.h>
#include <tizen_error.h>

#ifndef EXPORT_API
#define EXPORT_API __attribute__((__visibility__("default")))
#endif

#ifndef DEPRECATED_API
#define DEPRECATED_API __attribute__((__visibility__("default"), deprecated))
#endif

#ifndef DEPRECATED_TYPE
#define DEPRECATED_TYPE __attribute__((deprecated))
#endif

#endif // __TIZEN_H__