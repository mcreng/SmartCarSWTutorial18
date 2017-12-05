# Git 101

Author: Dipsy Wong ([dipsywong98](http://www.github.com/dipsywong98))

### 1. What is Git

Git is a "Google drive" for coders with version control, it can help the collaboration between coders. Github is just one of the "cloud service provider" and we are going to use it. You can also use git locally without a cloud (actually it is called a remote) for your own version control.

### 2. How it works

The most important concept is "commit". A commit is actually a record of all your codes. It can act as a roll back point when you do something sucks. All the versions are just all the commits. Every time you call commit, git takes a photo of you code, and records it as a newer version. 

The other important concept is "push" and "pull", which push is uploading your local new version (new commit) to github, and pull is downloading the new version in github to your computer. The details will be explained later.

### 3. Getting Started

- Create an account in github https://github.com/
- Install git https://git-scm.com/downloads
- Good link for visualization when learning git: https://learngitbranching.js.org/?NODEMO

### 4. Create Repo on GitHub

A repo(repository) is a programming project organized by git, and stored on some git server, which is GitHub.

To create a repo, login GitHub and [click me](https://github.com/new). Alternatively, you can go to your profile page https://github.com/{your username}?tab=repositories and click the "new" button. 

Enter you repo name and then click Create repository.

### 5. Set Up the Repo on Your Computer

#### 1. Set your Account for Git (Only need to do it once)

Open git bash, and execute:

```shell
git config --global user.email "your@email.com"
git config --global user.name "Your Name"
```

#### 2.Change Working Directory

_AKA let git know where you need git, and where to set up your repo_

Option1: Right click at your directory, click git bash here
   ![1_bash_here](C:\Users\dipsy\Desktop\ROBO\SmartCarSWTutorial18\img\git\1_bash_here.PNG)

Option2: Open git bash program, type

```shell
cd "you/dir/name"
```

#### 3. Clone Repo

```shell 
git clone https://github.com/{your username}/{your repo name}.git
```
You can get the git URL here


Upload and download 

​    

Git push and git pull 

​    

​    

Where to upload

​    

Git set-upstream origin ...... Git

​    

​    

What to upload and download

​    

A code commit, which is just version of code, and you need to describe what is changed in one sentence

​    

Git commit -m "your Message "

​    

​    

Decide what to keep track of

​    

git stage, git add

​    

​    

​    

Branch and merge

​    

When there is diverge version/ new feature/ different  people working, better use branch to avoid conflict/ as a restart point （aka 砍掉重煉不太痛）

​    

Master branch: Most likely the default main branch 

​    

​    

Open new branch 

​    

Git checkout -b branch-name

​    

​    

Goto existing branch

​    

Git checkout branch-name

​    

​    

Merge branch

​    

The version or feature converge

​    

Git checkout base-branch 

​    

Git merge source-branch 

​    

​    

If you are merging branch A to master and there is possible conflict, it is better to solve the conflict at A first, to make sure the new code is compatible with current code in master



git reset --hard



git stash
