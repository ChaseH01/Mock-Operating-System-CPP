This is the final project for WashU's CSE332 Object Oriented Programming Course. This project consisted of six studios and a final lab which synthezied and built off of the work in these studios. I made a copy of this project in a personal repo so that I could edit the readMe's in order to make them more helpful for viewers unfamiliar with CSE332 - the code remains unchanged.

This project was developed in collaboration with Matteo Dall'Olmo. While we worked together throughout, all design, implementation, and documentation in this repository were created and finalized by me as part of my personal portfolio.

Note: AI was used to format (but not to write) this ReadMe.

***

## ⚙️ Project Overview

The lab mimics a software simulation of a file system, some simple file types that may be stored in a file system, and a user interface similar to a command prompt or terminal that allows a user to interact with the file system and files it contains.

It allows for two types of files: `.img` and `.txt`. When creating or accessing files, be sure to remember these extensions.

***

## 🖼️ Image File Type

Note: We will be displaying files in the "terminal", so we are limited in what exactly an “image” is (we can’t print color, etc.). For this lab, an image will be an $n \times n$ board of pixels. Each pixel will either be an ‘X’ or a ’ ‘ (space) when the image file is read and displayed. When writing an image file, the file will be encoded as a `vector<char>` where the first $n \times n$ chars in the vector are either a ‘X’ or a ‘ ‘ (space). The last char in thevector will be the size ($n$) of the image.

For example, the input argument may be a `vector<char>` containing:
> `{ ‘X’, ‘ ‘, ‘X’, ‘ ‘, ‘X’, ‘ ‘, ‘X’,’ ‘, ‘X’, ‘3’ }`

***

## 💻 Commands

* **`cat`**: `cat` inputs data that will overwrite your chosen file.
    * To invoke this command, type: `cat <filename>`
* **`cat -a`**: appends input onto existing data.
    * To invoke this command, type: `cat -a <filename>`
* **`cp`**: creates a copy of a file and stores it in the filesystem under a new name.
    * To invoke this command, type: `cp <file_to_copy> <new_name_with_no_extension>`
* **`cr`**: is a macrocommand. Macrocommands are commands built out of other commands. `cr` allows a user to `touch` and `cat` on a file all in one.
    * Invoke this command by typing: `cr <new_file_name>`
* **`ds`**: opens a file and displays its formatted contents.
    * To invoke this command, type: `ds <filename>`
* **`ds -d`**: opens a file and displays its un-formatted contents.
    * To invoke this command, type: `ds <filename> -d`
* **`ls`**: displays all the names of the files currently in the file system.
    * To invoke this command, type: `ls`
* **`ls -m`**: displays every filename with its associated metadata.
    * To invoke this command, type: `ls -m`
* **`rm`**: removes a file from the file system.
    * To invoke this command, type: `rm <filename>`
* **`rn`**: is a macrocommand. Macrocommands are commands built out of other commands. `rn` copies a file with your desired new name, and then removes the old file.
    * Invoke this command by typing: `rn <file_to_copy> <new_name_with_no_extensions>`
* **`touch`**: creates a file.
    * To invoke this command, type: `touch <filename>`
* **`touch -p`**: creates a password protected file. Subsequent requests to view or edit this file will require the correct password.
    * To invoke this command, type: `touch <filename> -p`
    * *Note: password invocation has a small printing bug, but functionally works exactly as intended.*

***

## 🛠️ Design & Implementation

This lab closely resembles the setup of a professional C++ project. I implemented common design patterns in OOP, including **Abstract Factory**, **Visitor**, **Proxy**, **Command**, **Prototype**, **Composite**, and **Strategy** design patterns. I ensured this code is highly flexible and extensible by programming to an interface and ensuring the single responsibility principle was upheld strictly. I tested my work closely by running unique test cases. Most useful however, were the provided test cases by the professor for the studios and lab.

***

## ▶️ How to Run

To experience the mock OS from the final lab, configure **'lab5'** as the target and executable.
