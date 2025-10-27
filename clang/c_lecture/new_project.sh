#!/bin/bash

# 현재 스크립트가 있는 폴더를 기준으로 C_Lecture 경로 지정
BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_NAME="$1"

if [ -z "$PROJECT_NAME" ]; then
    echo "사용법: $0 프로젝트이름"
    exit 1
fi

PROJECT_DIR="$BASE_DIR/$PROJECT_NAME"

# 이미 존재하면 중단
if [ -d "$PROJECT_DIR" ]; then
    echo "프로젝트 '$PROJECT_NAME' 이미 존재함."
    exit 1
fi

# 폴더 구조 생성
mkdir -p "$PROJECT_DIR/.vscode"

# main.c 생성
cat <<EOF > "$PROJECT_DIR/main.c"
#include <stdio.h>

int main() 
{
    
}
EOF

# tasks.json 생성
cat <<EOF > "$PROJECT_DIR/.vscode/tasks.json"
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build $PROJECT_NAME",
            "type": "shell",
            "command": "gcc",
            "args": [
                "main.c",
                "-o",
                "$PROJECT_NAME"
            ],
            "options": {
                "cwd": "\${fileDirname}"
            },
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": "\$gcc"
        }
    ]
}
EOF

echo "프로젝트 '$PROJECT_NAME' 생성 완료."
echo "경로: $PROJECT_DIR"