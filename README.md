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

Assessing our way of working, we can semi-confidently say that our way of working is currently at the state of being "In Place", though the transition to this state is very recent. The whole team is using the same tools and practices to do their work, and every team member has access to these tools. The whole team is involved in the changes to be made to the way-of-working, although not to the same degree. We have been able to come so far in our way of working mostly thanks to the effort we spent on communicating and establishing a common ground. If we had not spent as much time on this step, there could be much more incoherency in our way of working. In order to move forward, our team needs to naturally apply our way of working to problems of different kinds in different contexts. We also need the evaluate our way of working in a detailed and continous manner, in order to assess its effectiveness in supporting our way of working.
