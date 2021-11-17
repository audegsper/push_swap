git add .
echo "git commit -m에 넣을 메세지를 넣어주세요."
read  msg
git commit -m "$msg"
git push "주소 넣기"
