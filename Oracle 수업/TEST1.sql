--- SNACK 테이블 생성
---> 과자 이름, 선호도, 가격, 열량
CREATE TABLE SNACK(
    SNACKNAME VARCHAR2(20),
    PREFRENSE INT,
    PRICE INT,
    CALORIE INT
);
---5~10개의 데이터 SNACK 테이블에 삽입
--(데이터는 각자 임의로 작성하기)
INSERT INTO SNACK(SNACKNAME, PREFRENSE, PRICE, CALORIE) 
VALUES('새우깡',10,1800,400);

INSERT INTO SNACK(SNACKNAME, PREFRENSE, PRICE, CALORIE) 
VALUES('먹태깡',6,2000,500);

INSERT INTO SNACK(SNACKNAME, PREFRENSE, PRICE, CALORIE) 
VALUES('감자깡',3,1600,300);

INSERT INTO SNACK(SNACKNAME, PREFRENSE, PRICE, CALORIE) 
VALUES('양파깡',1,1400,300);

INSERT INTO SNACK(SNACKNAME, PREFRENSE, PRICE, CALORIE) 
VALUES('고구마깡',2,1600,200);

--1. 모든 SNACK 데이터 검색하여 출력
SELECT * FROM SNACK ;

--2. SNACK 테이블의 데이터 개수 출력    데이터개수 검색해서 알아보기
--(COUNT함수 응용)
SELECT COUNT(*) FROM SNACK;

-- DELETE : 데이터 삭제 명령문
-- DELETE FROM 테이블명 WHERE 조건문;

--3. 아래에 속하는 데이터들 삭제한 뒤,       데이터 삭제 검색해서 알아보기
--	남아있는 데이터 출력
--- 가격이 2000원 이상인 과자 데이터 제거
--- 선호도가 1 이하인 과자 데이터 제거
--- 열량이 500 이상인 과자 데이터 제거
DELETE FROM SNACK WHERE PRICE >= 2000;
DELETE FROM SNACK WHERE PREFRENSE <= 1;
DELETE FROM SNACK WHERE CALORIE >= 500;
-- 삭제 확인
SELECT * FROM SNACK;

--- SNACK 테이블 삭제 (테이블 모두 삭제)
DROP TABLE SNACK;

