#!/bin/bash

while true
do
    
    echo "Press 1 to create a directory.";
    echo "Press 2 to delete a directory.";
    echo "Press 3 to display the current directory.";
    echo "Press 4 to change working directory.";
    echo "Press 5 to exit.";
    echo "Enter your choice: ";
    read choice;
    case "$choice" in
        1)
            echo "Enter name of new directory to be created: ";
            read dir;
            if [ -d $dir ]; then echo "Directory already exists";
            else mkdir $dir;
            fi
        ;;
        2) 
            echo "Enter the directory name to be deleted: ";
            read dir;
            rmdir $dir;
            echo "Directory deleted successfully";
            ls -t 
        ;;
        3)
            echo "Current Working Directory : ";
            pwd 
        ;;
        4)
            echo "Enter path to change the current directory: ";
            read path
            cd $path
            ls -i 
        ;;
        5)
            exit;
        ;;
        *)	
            echo "Invalid input,try again"
		;;
    esac
done