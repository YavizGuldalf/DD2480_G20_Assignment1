# DD2480 Assignment 1: DECIDE

### About

In this project, a hypothetical program for an anti-ballistic system is implemented according to the [requirement specifications](https://www.monperrus.net/martin/decide.pdf). The program decides whether a missile should be launched or not, and outputs either "LAUNCH" or "NO LAUNCH". Several pieces of input data is taken into consideration when deciding whether to launch or not. There are 15 "LIC's" implemented, which are functions that consider the input data and checks it against certain conditions that need to be fulfilled.

The program is fully written in the C language. It has unit tests (with positive, negative and invalid tests) for the 15 earlier mentioned LIC's. Additionally, there is testing for the entire launch sequence. 

### Credits

* For testing, the project uses [MinUnit](https://jera.com/techinfo/jtns/jtn002).

### Running the program


### Contributions

Yagiz: I have worked on the following parts in this project:
+ Implemented and wrote the documentation for LIC2, LIC7, LIC9, LIC11 and LIC13 calculations
+ Established the main testing framework
+ Created the tests (positive, negative and invalid) for LIC0, LIC7, LIC9, LIC11, LIC13 calculations
+ Implemented the intermediate variable calculations (CMV, FUV and PUM) as well as the main DECIDE() function
+ Contributed slightly to the makefile and code reviews

### Essence