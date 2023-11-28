import json # json 라이브러리 추가
import urllib.request # url라이브러리요청
import pymysql

# myurl에 API request URL을 넣는다
myurl = 'https://api.odcloud.kr/api/3047940/v1/uddi:633f7dab-ffb5-4843-bc65-bd7f3b99dfa2?page=1&perPage=1000&serviceKey=oOLjwwlEiv02I8IAl4hAxRvfBY4mNZgLQCum8yVEw2hJ0C9JPrCTsS0bt7gH%2Ft3PqVCf3yfdL%2BWaBMMdhSxexA%3D%3D'

# response변수에 요쳥한 URL열고 변수에 대입
response = urllib.request.urlopen(myurl)

# 읽을때 UTF8로 디코딩하는이유 한글이 깨질 수있음
response = response.read().decode('utf8')

print(response)

# response 데이터를 json 형태로 바꿈
data = json.loads(response)
# key가 'data'인 것만 가져옴
json_arr = data['data']

sql = 'insert into apitable(name,hp,menu) '
sql = sql + "values('%s', '%s', '%s')"

conn = pymysql.connect(
    host='localhost',
    user='root',
    password='1234',
    db='apidb',
    charset='utf8'
)

cur = conn.cursor()
for item in json_arr:
    cur.execute(sql % (item['상호명'],item['전화번호'],item['주메뉴']))

conn.commit()
# with이 없으므로 수동으로 닫아줌
conn.close()