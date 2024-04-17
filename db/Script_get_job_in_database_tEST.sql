--INSERT INTO Member_Info (id) VALUES('aeiou'); -- ok!

--SELECT id FROM Member_Info; -- ok!

--INSERT INTO Member_Info (id, pin_code, email, phnum) VALUES ('kkk', '1234', 'kkka', '01012345678'); -- ok!

--SELECT usernum FROM Member_Info ORDER BY ROWID DESC LIMIT 1; -- ok!

--SELECT id, pin_code FROM Member_Info; -- ok!

--SELECT co_name, notice_title, deadline FROM Company_Info ORDER BY RANDOM() LIMIT 3; -- ok!

--SELECT * FROM Company_Info WHERE loc || edu || co_size || co_name || notice_title || deadline || duty || working_date || intake || notice_addr || co_site || co_addr || CEO_name || est_date || employee_num || revenue || biz_cat || biz_content 
--LIKE '%서울%'; -- ok!

--SELECT company_num, loc, edu, co_size, co_name, notice_title, duty, working_date, intake, co_addr, est_date, biz_cat, biz_content FROM Company_Info WHERE loc || edu || co_size || co_name || notice_title || deadline || duty || working_date || intake || notice_addr || co_site || co_addr || CEO_name || est_date || employee_num || revenue || biz_cat || biz_content 
--LIKE '%성남%'; -- ok!

--SELECT company_num, loc, edu, co_size, co_name, notice_title, duty, working_date, intake, co_addr, est_date, biz_cat, biz_content FROM Company_Info WHERE 
--loc == '경기도 화성' AND edu == '학력 무관' AND co_size == '중소기업'; -- ok!

--SELECT notice_title, co_name, deadline, duty, working_date, intake, notice_addr FROM Company_Info WHERE company_num == '8'; -- ok!

--SELECT co_site, co_addr, CEO_name, est_date, employee_num, revenue, biz_cat, biz_content FROM Company_Info WHERE company_num == '8'; -- ok!