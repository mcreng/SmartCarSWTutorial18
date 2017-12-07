# Git 101

Author: Dipsy Wong ([dipsywong98](http://www.github.com/dipsywong98))

### 1. What is Git

Git is a "Google drive" for coders with version control, it can help the collaboration between coders. Github is just one of the "cloud service provider" and we are going to use it. You can also use git locally without a cloud (actually it is called a remote) for your own version control.

### 2. How it works

The most important concept is "commit". A commit is actually a record of all your codes. It can act as a roll back point when you do something sucks. All the versions are just all the commits. Every time you call commit, git takes a photo of you code, and records it as a newer version. 

The other important concept is "push" and "pull", which push is uploading your local new version (new commit) to github, and pull is downloading the new version in github to your computer. The details will be explained later.

### 3. Getting Started

- Create an account in github https://github.com/
  - You may also get a student pack for your account so that you can have infinite private repo (PS: use <your itsc>@ust.hk to register)
    https://education.github.com/pack
- Install git https://git-scm.com/downloads
  (remember to check git bash here, extremely convenient to use)
- Good link for visualization when learning git: 
  - https://learngitbranching.js.org/?NODEMO
  - https://onlywei.github.io/explain-git-with-d3/#freeplay
- You can also google some good software which can visualize your git repo

### 4. Set your Account for Git (Only need to do it once)

Open git bash, and execute:

```shell
git config --global user.email "your@email.com"
git config --global user.name "Your Name"
```

### 5. Create Repo on GitHub

A repo(repository) is a programming project organized by git, and stored on some git server, which is GitHub.

To create a repo, login GitHub and [click me](https://github.com/new). Alternatively, you can go to your profile page https://github.com/{your username}?tab=repositories and click the "new" button. 
![4](C:\Users\dipsy\Desktop\ROBO\SmartCarSWTutorial18\img\git\4.PNG)



Enter you repo name and then click Create repository.

### 6. Change Working Directory

_AKA let git know where you need git, and where to set up your repo_

#### Option1: 

Right click at your working directory, click git bash here

   ![1_bash_here](C:\Users\dipsy\Desktop\ROBO\SmartCarSWTutorial18\img\git\1_bash_here.PNG)

#### Option2: 

Open git bash program, type

```shell
cd "you/dir/name"
```

PS: please use option1

### 7. Get the Repository git URL 

Git URL for GitHub is `https://github.com/{your username}/{your repo name}.git`. But for lazy guys, you can copy and paste:

For non-empty repo, you can get the git URL here

![5.3](C:\Users\dipsy\Desktop\ROBO\SmartCarSWTutorial18\img\git\5.3.PNG)

New repo

![5.3_](C:\Users\dipsy\Desktop\ROBO\SmartCarSWTutorial18\img\git\5.3_.PNG)

### 8. Set up repo on your computer 

#### Option1: Clone Repo (This will create new folder containing the repo)

Execute:

```shell 
git clone https://github.com/{your username}/{your repo name}.git
```
#### Option2: Add remote (make current directory into a repo)

This is a bit advance, but more convenient than git clone if you know how to use

A remote is a git server as mentioned in "What is Git", and conventionally we name the main remote as `origin`. BTW, it is possible for one repository to have multiple origin.

```shell
#initialize this directory as a git repo, AKA create a hidden /.git directory
git init 

#add remote
git remote add origin https://github.com/{your username}/{your repo name}.git

#if the remote (GitHub repo) have existing code, pull it (download it)
#this line will be explain in next session
git pull origin master
```

This is useful when you have created an eclipse project, and you want to turn this project into a git repository. 

### 9. Basic Flow of Git

![Git Flow](C:\Users\dipsy\Desktop\ROBO\SmartCarSWTutorial18\img\git\Git Flow.png)

#### 9.0 Git Status

```shell
git status
```

This command can tell you most the information:

- Your current working branch (branch will be discussed later)
- Files that you haven't track
- Tracking files that have been modified
- Number of commits you are ahead of master

It is suggested to run this command before other git command to let you know what is your current status. Below can give your the idea on the information that `git status` provides.

#### 9.1 Git Pull (Download New Code)

Before start coding new stuff, remember to git pull. If there is new stuff on remote but not on your computer, and you have implement new stuff that you want to upload to remote, conflict will happen (There are other sources of conflict and will be discussed later). So always make sure your local repository is in sync with the remote before doing new stuff. To git pull:

```shell
git pull
```

#### 9.2 Git Add (Track New Files)

Git is a system which tracks the changes of the files, so you need to tell git which files you would like to track. To track a file:

```shell
#option 1: one by one
git add readme.md

#option 2: more than one
git add my_class.h my_class.cpp 

#option 3: wild card, * is corresponding to any sequence of characters
git add *.txt

#option 4: by directory
git add img/
```

The file just added will be directly staged. The files in the stage area are the files to commit.

#### 9.3 Git Stage (Stage Modified Files)

When the tracked files have changes and you want to record them, you need to stage the the files. To stage a file.

```shell
#option 1: one by one
git stage readme.md

#option 2: more than one
git stage my_class.h my_class.cpp 

#option 3: wild card, * is corresponding to any sequence of characters
git stage *.txt

#option 4: by directory
git stage img/
```

If you stage a file which is originally not tracked, it will become tracked and at the same time staged, which is same as `git add`.

#### 9.4 Git Commit (Record this stage)

A commit is the unit of git to track the versioning. 

It is done by recording all the changes in the stage area. After commit, you repo is move on by one version, and the committed changes will be saved, and the corresponding files will be marked as unchanged as well. 

Each commit will come along with a commit message (to describe what is changed, please make it short and precise) and a SHA (a unique id for the commit)

```shell
#commit the staged files, and prompt a vim editor for you to edit commit message
git commit

#if you dont know how to use vim, use this to enter commit message at once
git commit -m "my commit message"
```

if you want to type `git stage *` before commit, you can do the following to avoid typing `git stage *`. But make sure you know which files are going to be commit (always `git status` first).

```shell
git commit -a -m "my commit message"

#equivilent with
git stage *
git commit -m "my commit message"
```

##### 9.5 Git Push

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
