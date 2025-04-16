# !/bin/bash
python3 ./scripts/calculate_result.py `ls server*.log client.log` > results.log
echo "save result to results.log"
cat results.log
