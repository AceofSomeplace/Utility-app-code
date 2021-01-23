# Cloning the Utility App Assignment Repository - Visual Studio

This guide will detail how to clone your Utility App assignment repository to your local machine using GitHub desktop.

[Click here to view a video guide](https://www.loom.com/share/b28b0d72a06a452c9936c43c74c93841)

&nbsp;
&nbsp;

## Step 1

First you need to generate the repository by clicking this link: https://classroom.github.com/a/ifLOuQtk

&nbsp;
&nbsp;

## Step 2

Once you have clicked this link you will be taken to a page asking you to accept the assignment (you may be asked to login to GitHub and grant access to GitHub classroom).

This page will look similar to the below. Click ```Accept this assignment```.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/Utility-App-Accept.png">
</p>

&nbsp;
&nbsp;

## Step 3

GitHub classroom will now generate your own unique repository for the assignment. Please wait while it completes the import process.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/utility-generating.png">
</p>

&nbsp;
&nbsp;

## Step 4

Once imported you will be presented with a success message like the one below. Included here is a URL for your repository on GitHub keep a note of this URL.


<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/utility-created.png">
</p>

&nbsp;
&nbsp;

## Step 5

So far we have successfully created your repository on GitHub, but we need to download this to your machine so you can write your code and then send this back to GitHub. For this we will use GitHub desktop.

Open GitHub desktop and clone the repository. If you have no existing repositories you can do this by clicking the ```Clone a Repository``` button on the opening screen. If you already have some repositories downloaded you can add another on by selecting ```File --> Clone Repository``` from the menu bar.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/get-started-screen.png">
</p>

&nbsp;
&nbsp;

## Step 6

You will be presented with *Clone a Repository*  screen similar to the one below. You should look for the repository you wish to clone from those listed. This will be named something like: CodeLab-I-20-21/utility-app-yourgithubusername

Click ```Choose...```next to the local path field and browse to sensible location on your machine to save the repository, eg: ```Documents → Dev```.

Once you have selected a folder on your machine click ```Clone``` to download the repository.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/clone-utility.png">
</p>

&nbsp;
&nbsp;

## Step 7

You should now have a copy of the repository from Github on your local machine and GitHub desktop should look like the below screen.


<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/utility-app-cloned.png">
</p>

&nbsp;
&nbsp;

## Step 8

Now we need to create the project file to write the code. Select ```Create a new project``` from the startup screen (or ```File → New Project``` if already in Visual Studio).

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/getting-started-vs.png">
</p>

&nbsp;
&nbsp;

## Step 9

Select ```Empty Project``` from the templates and click ```next```.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/empty-project.png">
</p>

&nbsp;
&nbsp;

## Step 10

Configure your project settings:

* In the ```Project Name``` box provide a name for the project (e.g: UtilityApp)
* In the ```Location``` box browse to the location where you cloned the repository to.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/configure-project-utility.png">
</p>

&nbsp;
&nbsp;

## Step 11

You will be presented with the following screen (Solution Explorer may appear on the left or the right).

* In the solution explorer right click the ```Source Files``` folder
* Click ```Add → New Item``` from the popup menu that appears

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/add-new-utility.png">
</p>

&nbsp;
&nbsp;

## Step 12

Add a new C++ (```.cpp```) file and name it ```main.cpp```. Click ```Add```.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/main-utility.png">
</p>

&nbsp;
&nbsp;

## Step 13

Your main.cpp file will initially be blank. Add the following 'skeleton' code ready to create the rest of your program.

```C++
#include <iostream>
using namespace std;

int main(){


  return 0;
}
```

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/vs-project.png">
</p>

&nbsp;
&nbsp;

## Step 14

As you write your code Github Desktop will keep track of your changes in your ```main.cpp``` file and any other files you add to your project. You should make regular commits to ensure you can fall back to previous versions if things go wrong. To make commits write a descriptive message for the changes you have made and click ```commit to master```.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/initial-commit-vs.png">
</p>

&nbsp;
&nbsp;

### Step 15

When making commits you should also push your your work to GitHub this will make sure you have a backup of your work. Most importantly when you are happy with your final solution don't forget to make sure you make one final commit and push to your final code before the deadline. To push code to GitHub click ```Push Origin``` after making a commit.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/push-origin.png">
</p>

&nbsp;
&nbsp;

### Step 16

To check your code has submitted correctly go to your repository on GitHub, the URL for this will be: ```github.com/codelab-i-20-21/utility-app-YOURGITHUBUSERNAME```.

You can also easily get to your repository on GitHub by clicking the ```View on GitHub``` button in GitHub Desktop.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/view-on-github.png">
</p>
