echo Test X: "(shortest distance, number of paths)"
echo TEST 1: "(2,2)"
./greedy_robot 1 3 4 4 3

echo TEST 2: "(Already there)"
./greedy_robot 2 1 1 1 1

echo TEST 3: "(NP, 0)"
./greedy_robot 1 1 1 5 1

echo TEST 4: "2 1 2 3 5"
./greedy_robot 2 1 2 3 5

echo TEST 5: "2 1 1 -1 -3"
./greedy_robot 2 1 1 -1 -3

echo TEST 6: "1 1 1 1 1"
./greedy_robot 1 1 1 1 1

echo TEST 7: "2 -1 -2 3 4"
./greedy_robot 2 -1 -2 3 4

echo TEST 8: "-2 1 2 3 4"
./greedy_robot -2 1 2 3 4

echo TEST 9: "4 0 0 0 4"
./greedy_robot 4 0 0 0 4

echo TEST 10: "2 2 0 0 0"
./greedy_robot 2 2 0 0 0

echo TEST 11: "5 0 0 0 -5"
./greedy_robot 5 0 0 0 -5

echo TEST 12: "1 -1 0 0 0"
./greedy_robot 1 -1 0 0 0

echo TEST 13: "2 -2 0 -4 3"
./greedy_robot 2 -2 0 -4 3
