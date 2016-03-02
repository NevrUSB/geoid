This page contains instructions how-to compile Geoid

### Under Linux ###
To install Geoid you need subversion to obtain source code and Qt4 development libraries to compile it. The way you install these packages depends on your distribution.
For example, under ubuntu you can execute this command:
```
sudo apt-get install libqt4-dev subversion
```
Once you installed this libraries you can get the source code of Geoid and compile it:
```
svn checkout http://geoid.googlecode.com/svn/trunk/ geoid
cd geoid
qmake
make
```
Geoid executable binary will appear in bin/ subfolder


### Under Windows ###
First of all you should install Qt development libraries and MinGW(which is a Windows port of GNU Compilers). Qt setup file is available here: http://trolltech.com/developer/downloads/qt/windows (at the time of writing it was qt-win-opensource-4.3.4-mingw.exe). During installation it will suggest you downloading MinGW - you should agree.

The next step is installing subversion. You can download the latest version here : http://subversion.tigris.org/servlets/ProjectDocumentList?folderID=91 At the time of writing it was svn-1.4.6-setup.exe .

Next you should do a small modification to the following file: C:\Qt\4.3.4\bin\qtvars.bat (version of Qt of course may differ). Find in the file the line:
```
set PATH=C:\Qt\4.3.4\bin
```
And change it to
```
set PATH=%PATH%;C:\Qt\4.3.4\bin
```
That's because this Qt bat file replaces %PATH% variable, which contains path to subversion binaries. Once you finish, go to the start Menu: Programs -> Qt by Trolltech (OpenSource) -> Qt Command Prompt. Change the directory to you projects directory, and type the following commands:
```
svn checkout http://geoid.googlecode.com/svn/trunk/ geoid
cd geoid
qmake
make
bin\geoid.exe
```
This will compile and run geoid