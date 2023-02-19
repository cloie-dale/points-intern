# Intern Test
This repository contains my solution to the Fetch Rewards intern application questinos.

Language: C++

<h3>  Downloading g++: </h3>

If you are unsure if you have g++ run command the ``g++ --version``

&emsp;**Mac:**

&emsp; &emsp;Install Xcode and follow the steps for g++ from [here](https://developer.apple.com/xcode/).
<br />

&emsp;**Windows:**

&emsp; &emsp;Instructions for downloading MinGW and using it to run g++ are found [here](https://semicolon.dev/windows/how-to-install-mingw-gcc-g-compiler-windows-10-11-2023). 
<br />

&emsp;**Ubuntu:**

&emsp;&emsp; run command ``sudo apt install build-essential``

&emsp;&emsp; run command ``sudo apt -y install g++-11``

&emsp;&emsp;If the project does not compile after doing this follow the steps found [here](https://linuxhint.com/install-and-use-g-on-ubuntu/).
<br />
<br />

<h3>Instructions to Run Project:</h3>

To compile use command: ``g++ Payer.cpp main.cpp -o transaction``

To run use command: ``./transaction "Points" "filename.csv"``

"Points" should be the number of points you want to use, and "filename.cvs" should be the name of the csv file you want to use. 

Do not include the quotes in the run command, but make sure to include the ``.csv`` file extension.
<br />
<br />
    
<h3>Assumptions:</h3>

The input file will match the formating of the example exactly.

If a negative transaction is made, then those points were removed from the first positve transaction made by the same payer.
