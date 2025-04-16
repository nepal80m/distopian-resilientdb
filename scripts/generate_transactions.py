import subprocess
import random
import time


def generate_transactions_by_count(num_transactions=500):
    print(f"Generating {num_transactions} transactions...")

    for i in range(num_transactions):
        random_key = random.randint(0, 9)

        cmd = [
            "bazel-bin/service/tools/kv/api_tools/kv_service_tools",
            "service/tools/config/interface/service.config",
            "set",
            str(random_key),
            "helloworld",
        ]

        try:
            result = subprocess.run(cmd, capture_output=True, text=True)
            print(
                f"Transaction {i+1}/{num_transactions}: Set key={random_key}, value=helloworld"
            )
            if result.returncode != 0:
                print(f"Error in transaction {i+1}: {result.stderr}")
        except Exception as e:
            print(f"Error executing transaction {i+1}: {str(e)}")

        # time.sleep(0.01)


def generate_transactions_by_time(run_time=60):
    print(f"Generating transactions for {run_time} seconds...")

    start_time = time.time()
    num_transactions = 0
    while time.time() - start_time < run_time:
        random_key = random.randint(0, 9)

        cmd = [
            "bazel-bin/service/tools/kv/api_tools/kv_service_tools",
            "service/tools/config/interface/service.config",
            "set",
            str(random_key),
            "helloworld",
        ]

        try:
            result = subprocess.run(cmd, capture_output=True, text=True)
            num_transactions += 1
            print(
                f"Transaction {num_transactions}: Set key={random_key}, value=helloworld"
            )
            if result.returncode != 0:
                print(f"Error in transaction {num_transactions}: {result.stderr}")
        except Exception as e:
            print(f"Error executing transaction {num_transactions}: {str(e)}")


if __name__ == "__main__":
    generate_transactions_by_time(60)
