/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <fstream>
#include <random>
#include <chrono>
#include <thread>

#include "common/proto/signature_info.pb.h"
#include "interface/kv/kv_client.h"
#include "platform/config/resdb_config_utils.h"

using resdb::GenerateReplicaInfo;
using resdb::GenerateResDBConfig;
using resdb::KVClient;
using resdb::ReplicaInfo;
using resdb::ResDBConfig;

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("<config path> [num_transactions]\n");
    return 0;
  }

  std::string client_config_file = argv[1];
  int num_transactions = 500;  // Default number of transactions
  if (argc >= 3) {
    num_transactions = std::stoi(argv[2]);
  }

  ResDBConfig config = GenerateResDBConfig(client_config_file);
  config.SetClientTimeoutMs(100000);

  KVClient client(config);

  // Initialize random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 9);

  printf("Starting to generate %d transactions...\n", num_transactions);

  for (int i = 0; i < num_transactions; i++) {
    // Generate random key between 0-9
    int random_key = dis(gen);
    
    // Set the key-value pair
    client.Set(std::to_string(random_key), "helloworld");
    
    printf("Transaction %d/%d: Set key=%d, value=helloworld\n", 
           i + 1, num_transactions, random_key);

    // Small delay to prevent overwhelming the system
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  printf("Finished generating %d transactions\n", num_transactions);
  return 0;
} 