-- 이걸써야 스크립트 출력 DBMS_OUTPUT.PUT_LINE
SET SERVEROUTPUT ON; 

--THINGS 테이블 생성
--	품목명(NAME)기본키  가격(PRICE) 재고(CNT)
CREATE TABLE THINGS(
    NAME VARCHAR2(20) PRIMARY KEY,
    PRICE INT,
    CNT VARCHAR2(20)
);

--데이터 7개 생성 INSERT INTO로 
INSERT INTO THINGS VALUES('가위',2000,'10');
INSERT INTO THINGS VALUES('청테이프',1800,'6');
INSERT INTO THINGS VALUES('노트',1500,'20');
INSERT INTO THINGS VALUES('포스트잇',1300,'30');
INSERT INTO THINGS VALUES('볼펜',1000,'40');
INSERT INTO THINGS VALUES('연필',1000,'60');
INSERT INTO THINGS VALUES('지우개',800,'22');

-- 입력 확인 
SELECT * FROM THINGS;


--스크립트 출력 상에 모든 데이터가 사라집니다 를 출력하며
--테이블상 모든 데이터를 지우는 프로시저 정의 및 호출

-- 데이터 지우고 모든 데이터가 사라집니다를 출력하는 프로시저
CREATE OR REPLACE PROCEDURE DEL_THINGS
IS BEGIN

DELETE FROM THINGS;
-- 스크립트 출력에 사용되는 PL문 


END DEL_THINGS;
/

-- 프로시저 호출
EXEC DEL_THINGS();

/
--프로시저 : 구현을 해두고 호출을 별도로 해야했음
-- 트리거 : 방아쇠 특정 명령문을 수행했을 때 자동으로 호출됌
--          구현하는 문법은 있지만 호출하는 문법은 별도로 없음
-- 트리거 선언
--CREATE OR REPLACE TRIGGER 트리거명
--[BEFORE/AFTER] [트리거 적용할 명령문] -- BEFORE INSERT
--ON 테이블명
--(FOR EACH ROW) -- 작성해두면 트리거 적용한 명령문 실행할 때마다 수행이 된다
--                -- 생략할시 딱 한번만 실행하고 그 후론 실행 안됨
--DECLARE        
---- 선언한다, 변수 선언하는 부분
--BEGIN           
---- 트리거 본문 작성하는 부분
--END;
--/

-- DDL(데이터 구조 명령어)에 대한 트리거 작성해두고
-- BEGIN-END 사이에 DML(데이터 명령어) 명령어 수행

-- INSERT문 수행 시, "데이터를 추가합니다." 트리거 선언 
CREATE OR REPLACE TRIGGER ALARM_INSERT
BEFORE INSERT ON THINGS
FOR EACH ROW
DECLARE BEGIN
DBMS_OUTPUT.PUT_LINE('데이터를 추가합니다');
END;
/

-- DELETE문 수행시 '데이터 삭제' 트리거 선언
CREATE OR REPLACE TRIGGER ALARM_DELETE
AFTER DELETE ON THINGS
FOR EACH ROW
DECLARE BEGIN
DBMS_OUTPUT.PUT_LINE('데이터 삭제');
END;
/

-- 1. DDL(데이터 구조 명령어)에 대한 트리거 작성해두고,
--      BEGIN-END 사이 DML(데이터 명령어) 명령어 통해 테스트 데이터 삽입
-- 2. DML(데이터 명령어)에 대한 트리거 작성해두고,
--      단순 출력문 수행
