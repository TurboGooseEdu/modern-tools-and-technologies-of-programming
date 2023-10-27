#!/bin/bash

SRC="https://spbu.ru/sveden/education"
DST="./result"
PRB=false

OPTS=$(getopt -o s:d:p --long source:,destination:,probe -- $@)
if [ $? -ne 0 ]; then
    echo "Wrong input"
    exit 1
fi

eval set -- $OPTS

while true; do
    case $1 in
    -s | --source)
        SRC=$2
        shift 2
        ;;
    -d | --destination)
        DST=$2
        shift 2
        ;;
    -p | --probe)
        PRB=true
        shift
        ;;
    --)
        shift
        break
        ;;
    *)
        exit 1
        ;;
    esac
done

if [ -z "$SRC" ] || [ -z "$DST" ]; then
    exit -1
fi


mkdir -p $DST


dl_spbu_s_e () {
    curl $SRC -s --compressed -H "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:109.0) Gecko/20100101 Firefox/118.0" -H "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8" -H "Accept-Language: ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3" -H "Accept-Encoding: gzip, deflate, br" -H "DNT: 1" -H "Connection: keep-alive"
}

dl_spbu_oop () {
    local result=$(dl_spbu_s_e grep -o -E "'https://nc\.spbu\.ru/.+?'" | sed "s/'//g" | grep -oP 'https://nc\.spbu\.ru/s/[^\s<>"'\'']+' | sort | uniq )
    if [ $PRB == true ]; then
        echo "probing"
        return $result | sort -R | head -n 3
    else
        return $result
    fi
}

function download {
    if ! wget -P $DST $1/download; then
        >&2 echo "Cannot download $1"
        return 15
    fi
}


function unarchive {
    for file in $1/*; do
        if [ -f $file ]; then
            unar -f $file -o $1
        fi
    done
}


for url in $(dl_spbu_oop); do
    download ${url}
done

unarchive $DST