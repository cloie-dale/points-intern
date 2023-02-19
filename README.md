# Intern Test
This repository contains my solution to the Fetch Rewards intern application questinos.

Language: C++

To compile use command: ``g++ Payer.cpp main.cpp -o transaction``

To run use command: ``./transaction "Points" "filename.csv"``

"Points" should be the number of points you want to use, and "filename.cvs" should be the name of the csv file you want to use. 

Do not include the quotes in the run command, but make sure to include the ``.csv`` file extension.

Assumptions:

The input file will match the formating of the example exactly.

If a negative transaction is made, then those points were removed from the first positve transaction made by the same payer.
