# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "kv_client",
    srcs = ["kv_client.cpp"],
    hdrs = ["kv_client.h"],
    deps = [
        "//interface/rdbc:transaction_constructor",
        "//proto/kv:kv_cc_proto",
    ],
)

cc_library(
    name = "contract_client",
    srcs = ["contract_client.cpp"],
    hdrs = ["contract_client.h"],
    deps = [
        "//common:json",
        "//interface/rdbc:transaction_constructor",
        "//proto/contract:account_cc_proto",
        "//proto/contract:contract_cc_proto",
        "//proto/contract:rpc_cc_proto",
        "//proto/kv:kv_cc_proto",
    ],
)
