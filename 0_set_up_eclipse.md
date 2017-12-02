# Set Up Eclipse

Author: Dipsy Wong ([dipsywong98](http://www.github.com/dipsywong98)) (by copying and pasting old tutorials)

This section will cover how to set up eclipse for flashing program to MCU and setting up the development environment

If you want to set up eclipse for console program, please refer to 
https://github.com/mcreng/SmartCarSWTutorial18/blob/master/1_basic_assignment.md

### 1.Download and Install the Essential Software

- Eclipse C++ (Suggested version: Neon1, never use Neon2)
  http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/neon1
- GNU Tools for ARM
  https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads
- Segger J-Link software pack https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack
- GNU Make 
  - windows: http://gnuwin32.sourceforge.net/packages/make.htm
  - mac:https://code.google.com/archive/p/rudix/downloads
### 2. Install Plug-in for Eclipse
- GNU ARM eclipse Plugins

  - [Help]->[Install New Software...]
  - Type http://gnuarmeclipse.sourceforge.net/updates in the textbox next to [Work with] label

    - Check the item [GNU ARM C/C++] in the CheckedListBox below
    - Press [Next]->[Next]->Accept license agreement & [finish]
- EGit
  - [Help]->[Install New Software...]
  - Type http://download.eclipse.org/egit/updates in the textbox next to [Workwith] label
  - Check the items [Eclipse Git Team Provider] & [JGit] in the CheckedListBox below
  - Press [Next]->[Next]->Accept license agreement & [finish]

### 3. Library Setting

#### 3.1 Download the Library by Git Pull

- [Window]->[Open Perspective]->[Other...]->Select [Git]->[OK]
- Copy https://github.com/hkust-smartcar/libsccc.git (Library)
  - Click [Git Repositories] tab
  - { Ctrl + V } / RightClick & [Paste Repository Path or URI]
  - [Next] -> [Next] -> [Finish]
- Right Click [libsccc] -> [Pull]

#### 3.2 Import the Library to Eclipse

- Goto [C/C++ perspective] on the top-right corner
- RightClick blank space on [Project Explorer] tab
- [C/C++ : Existing Code as Makefile Project] -> [Next]
- Select Cross GCC
- Name the new project
- Set the existing code location
- [Finish]

#### 3.3 Discovery Option Setting

- [Window] -> [Preferences] -> [C/C++ : Property Pages Settings]
- Check [Display “Discovery Options” page]
- [Apply]
- [OK]

#### 3.4 Properties Setting

- RightClick [libsccc] on [Project Explorer] tab -> [Properties]
- Select [C\C++ Build]
- Uncheck [Generate Makefiles automatically]


- Goto [Behavior] tab
- Uncheck [Stop on first build error]
- Check [Enable parallel build] (Optional)
- [Apply]


- Goto [C/C++ Build : Discovery Options]
- Tools: [Cross G++ Compiler]
- Check [Automate discovery of paths and symbols]
- Discovery profile: [Managed Build System - ...]
- Compiler invocation command : “arm-none-eabi-g++”
- Append “ –std=gnu++11” to Compiler invocation argument


- Goto [C/C++ Build : Environment]
- [Add...] -> Name: “ARM_TOOLCHAIN” -> Value: { Path of GNU Tools for ARM folder }
- [Add...] -> Name: “SCCC_BUILD” -> Value: “DEBUG”
- [Add...] -> Name: “SCCC_CONFIG” -> Value: “2017_INNO”
- Append { Path of GNU Tools for ARM folder }\bin to [PATH] Variable
- Append { Path of GNU Make folder }\bin to [PATH] Variable
- [Apply]


You can try to build the library

### 4. Project Setting

whenever you want to create a new project for programming smart car, you can start from this section. It is always a good measure to have a spare project for testing.

#### 4.1Create New Project

- Right-click on [Project Explorer] -> [New] -> [C++ Project]
- Project Type: [Executable : Empty Project], Toolchains: [Cross GCC]
- -> [Next] -> [Next]
- Cross compiler prefix: “arm-none-eabi-”
- Cross compiler path: { Path to GNU Tools for ARM }
- [Finish]

#### 4.2 Property Setting

repeat 3.4

- Goto [C/C++ Build : Environment]
- [Add...] -> Name: “LIBSCCC_BIN_PATH” -> Value: { Path of library folder }\lib
- [Add...] -> Name: “LIBSCCC_INC_PATH” -> Value: { Path of library folder }\inc
- [Apply]

**Remember that variable [SCCC_CONFIG] of both library and your own project must be the same.**

#### 4.3 Include the Library to your Project

- Goto [C/C++ General : Paths and Sybmols]
- Goto [Includes] tab
- Select Languages: [GNU C++]
- [Add....] -> [Workspace...] -> Select [libsccc : inc]-> [OK] -> [OK]

- Goto [C/C++ Build]
- Goto [Builder Settings] tab
- Remove “Debug” from Build directory

#### 4.4 Download linker's script and makefile

- Download all files in “Linker Script/build” folder on the Google Drive
- Create a new folder called “build” and put those files into it
- Download all files in “Makefile” folder on the Google Drive
- Put them into the project

#### 4.5 Download main.cpp

- Download main.cpp in “Example main.cpp” folder on the Google Drive
- Create a new folder called “src” and put main.cpp into it
- Don’t change this part in main.cpp !!!!!!!

Try to build the project, if no error, proceed to 5. Debugger Setting

### 5 Debugger setting

(After you finish building the project without error)

#### 5.1 New Debug Config

- Press the triangle next to a “BUG”
- [Debug Configurations...]
- RightClick [GDB SEGGERJ-Link Debugging
- [New]

#### 5.2 Select Binary

- You should find something like “bin/??????.elf” here (This will be automatically generated upon successful project build)

- If not, you should press [Search Project...] and find it

- Then, you should enable auto build because there is always someone who
  debugs a million times without rebuilding the project. XD

#### 5.3 Select MCU and J-Link

- Goto [Debugger] tab
- Device name: “MK60FN1M0xxx15” (MCU)
- SWD (small J) or JTAG(J-Link) (big J)
- Uncheck [Allocate console for semihosting and SWO]

#### 5.4 No Semi-hosting 

- Goto [Startup] tab
- Uncheck [Enable semihosting]
- [Apply]

### 6. Done and Enjoy Your Smart Car Journey 😘

Whenever you want to flash program, clean project -> build project -> click the debugger