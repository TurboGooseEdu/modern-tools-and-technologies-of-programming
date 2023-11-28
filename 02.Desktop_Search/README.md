# SPbSU syllabus indexer

![workflow-status](https://github.com/TurboGooseEdu/modern-tools-and-technologies-of-programming/actions/workflows/shellcheck.yaml/badge.svg)


This script downloads syllabuses from SPbSU official site and index them using Recoll - a powerful desktop search tool that provides full-text search capabilities.

After indexing search can be performed with the following command:
```shell
recollq "search query"
```

## Prerequisites
Before using script you have to install Unar (zip unarchiver) and Recoll:

```shell
sudo apt-get update
sudo apt-get install unar
sudo apt-get install recoll
```

## Usage
```
./import_umd -s "https://spbu.ru/sveden/education" -d "./target_directory" [-p]

-s | --source       URL to download from. Default is "https://spbu.ru/sveden/education".
-d | --destination  Directory path to save the downloaded files. Default is "./result".
-p | --probe        Optional: Download 3 random files when specified.
```