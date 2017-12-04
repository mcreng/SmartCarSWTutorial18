# Git 101

Author: Dipsy Wong ([dipsywong98](http://www.github.com/dipsywong98))

### What is Git

Git is a "Google drive" for coders with version control, it can help the collaboration between coders. Github is just one of the "cloud service provider" and we are going to use it. You can also use git locally without a cloud (actually it is called a remote) for your own version control.

### How it works

The most important concept is "commit". A commit is actually a record of all your codes. It can act as a roll back point when you do something sucks. All the versions are just all the commits. Every time you call commit, git takes a photo of you code, and records it as a newer version. 

The other important concept is "push" and "pull", which push is uploading your local new version (new commit) to github, and pull is downloading the new version in github to your computer. The details will be explained later.

### Getting Started

- Create an account in github https://github.com/
- Install git https://git-scm.com/downloads
- Good link for visualization when learning git: https://learngitbranching.js.org/?NODEMO

### Set your Account for Git

```shell
git config --global user.email "your@email.com"
git config --global user.name "Your Name"
```

### Change Working Directory

_AKA let git know where you need git_

Option1: Right click at your directory, click git bash here
   ![1_bash_here](C:\Users\dipsy\Desktop\ROBO\SmartCarSWTutorial18\img\git\1_bash_here.PNG)

Option2: Open git bash program, type

```shell
cd "you/dir/name"
```

###Clone Repo



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