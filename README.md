# Basic CI/CD

Development of a simple **CI/CD** for the C project. Building, testing, deployment.

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [Setting up the gitlab-runner](#part-1-setting-up-the-gitlab-runner)  
    1.2. [Building](#part-2-building)  
    1.3. [Codestyle test](#part-3-codestyle-test)   
    1.4. [Integration tests](#part-4-integration-tests)  
    1.5. [Deployment stage](#part-5-deployment-stage)  
    1.6. [Bonus. Notifications](#part-6-bonus-notifications)  

## Chapter I

### Part 1. Setting up the **git**

##### Start *Ubuntu Server 22.04 LTS* virtual machine.

##### Download and install **git** on the virtual machine.

### Part 2. Building

Write a stage for **CI** to build applications from the *SimpleBashUtils* project.

In the _.ci.yml_ file, add a stage to start the building via makefile from the _SimpleBashUtils_ project.

Save post-build files (artifacts) to a random directory with a 30-day retention period.

**== If the project *SimpleBashUtils* is not fulfilled  ==**


Write a stage for **CI** to build *DO* application from the code-samples folder.

In the _.ci.yml_ file, add a stage to start the building via makefile from the code-samples folder.

Save post-build files (artifacts) to a random directory with a 30-day retention period.


### Part 3. Codestyle test

#### Write a stage for **CI** that runs a codestyle script (*clang-format*).

##### If the codefile didn't pass, "fail" the pipeline.

##### In the pipeline, display the output of the *clang-format* utility.

### Part 4. Integration tests

#### Write a stage for **CI** that runs integration tests.

##### For the *SimpleBashUtils* project, you can take your already written integration tests.

##### For the project from the code-samples folder, write integration tests yourself. The tests can be written in any language (c, bash, python, etc.) and should call the built application to check its validity on different cases.

##### Run this stage automatically only if the build and codestyle test passes successfully.

##### If tests didn't pass, "fail" the pipeline.

##### In the pipeline, display the output of the succeeded / failed integration tests.

### Part 5. Deployment stage

##### Start the second virtual machine *Ubuntu Server 22.04 LTS*.

#### Write a stage for **CD** that "deploys" the project on another virtual machine.

##### Run this stage manually, if all the previous stages have passed successfully.

##### Write a bash script which copies the files received after the building (artifacts) into the */usr/local/bin* directory of the second virtual machine using **ssh** and **scp**.

##### In the _.ci.yml_ file, add a stage to run the script you have written.

##### In case of an error, fail the pipeline.

As a result, you should get a ready-to-use application from the *SimpleBashUtils* project (*cat* and *grep*) or an application from the code-samples folder (*DO*) on the second virtual machine (depending on what you did).

### Part 6. Bonus. Notifications

#### Set up notifications of successful/unsuccessful pipeline execution via bot in *Telegram*.
- The text of the notification must contain information on the successful passing of both **CI** and **CD** stages.
- The rest of the notification text may be arbitrary.
