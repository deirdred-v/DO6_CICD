#!/bin/bash

PROD_IP=10.10.10.102
SSH_KEY=.ssh/id_ed25519
USER=server


ssh -i $SSH_KEY $USER@$PROD_IP "sudo tee /usr/local/bin/s21_cat > /dev/null" < src/cat/s21_cat
ssh -i $SSH_KEY $USER@$PROD_IP "sudo chmod +x /usr/local/bin/s21_cat"

ssh -i $SSH_KEY $USER@$PROD_IP "sudo tee /usr/local/bin/s21_grep > /dev/null" < src/grep/s21_grep
ssh -i $SSH_KEY $USER@$PROD_IP "sudo chmod +x /usr/local/bin/s21_grep"
