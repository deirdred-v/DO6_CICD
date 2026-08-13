#!/bin/bash
STATUS_TEXT="$1"
TOKEN="tocken" #The token is hidden for security reasons. To use it replace "token" with "your_token".
CHAT_ID="chat_id" #The chat ID is hidden for security reasons. To use it replace "chat_id" with "your_chat_id"
URL="https://api.telegram.org/bot$TOKEN/sendMessage"

TEXT="Deploy status: $STATUS_TEXT%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_NAME"

curl -s -d "chat_id=$CHAT_ID&disable_web_page_preview=1&text=$TEXT" $URL