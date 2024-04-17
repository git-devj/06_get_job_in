#include <string> // 문자열 클래스 헤더 파일 | string 객체, getline() 함수 등 | iostream에 내장
#include <fstream> // 파일 입출력 클래스 헤더 파일 | ifstream 클래스 등 | iostream에 내장
#include <iostream> // 입출력 헤더 파일 | cout 객체 등
#include <unistd.h> // C POSIX 라이브러리 헤더 파일 | sleep() 함수 등
#include <sqlite3.h> // sqlite3 헤더 파일 | SQLite 객체, 함수 등
#include <algorithm> // 요소, 배열 작업 헤더 파일 | find() 함수 등

using std::string, std::to_string; // string(문자열 / 객체), to_string(수를 string 형태로 / 함수) 사용
using std::ifstream; // ifstream(파일을 프로그램에 입력 / 클래스) 사용
using std::cout, std::endl, std::cin, std::cerr; // cout(출력 / 객체), endl(줄 바꿈 / 함수), cin(입력 / 객체), cerr(즉시 출력 / 객체) 사용
using std::find, std::fill; // find(구조 내 요소 찾기 / 함수), fill(요소를 특정 값으로 채우기 / 함수) 사용


struct get_job_in_print // 취업in 로고 출력 구조체
{
    string rint; // 로고 출력 문자열
}p;

struct ui_num // ui 숫자 구조체
{
    int exit = 0; // 나가기 정수
    int select = 0; // 옵션 정수
}ui;

struct insert_user_info // 회원가입 유저 구조체
{
    string id; // 아이디
    string pin_code; // 핀 번호
    string email; // 이메일
    string phnum; // 휴대전화 번호
    string usernum; // 회원 번호
    int id_judge = 0; // 아이디 오류 확인 판단 값
    int pin_judge = 0; // 핀 번호 오류 확인 판단 값
    int email_judge = 0; // 이메일 오류 확인 판단 값
    int phnum_judge = 0; // 휴대전화 번호 오류 확인 판단 값
}join;

struct user_info // 가입된 유저 구조체
{
    const unsigned char* id; // 아이디
    const unsigned char* pin_code; // 핀 번호
    const unsigned char* email; // 이메일
    const unsigned char* phnum; // 휴대전화 번호
    const unsigned char* usernum; // 회원 번호
}user;

struct query_sentence // 쿼리문 구조체
{
    string check_id = "SELECT id FROM Member_Info;"; // 아이디 확인 쿼리문
    string check_email = "SELECT email FROM Member_Info;"; // 이메일 확인 쿼리문
    string check_phnum = "SELECT phnum FROM Member_Info;"; // 휴대전화 번호 확인 쿼리문
    string check_usernum = "SELECT usernum FROM Member_Info ORDER BY ROWID DESC LIMIT 1;"; // 회원 번호 확인 쿼리문
    string all_insert_sentence; // 모든 입력 조합 string 쿼리문
    string insert_all = "INSERT INTO Member_Info (id, pin_code, email, phnum) VALUES ('"; // 모든 입력 쿼리문
    string end = ");"; // 마무리 쿼리문
    string read_user_sentence = "SELECT id, pin_code FROM Member_Info;"; // 로그인을 위한 아이디, 핀 번호 읽는 쿼리문
    string read_rand_company_sentence = "SELECT co_name, notice_title, deadline FROM Company_Info ORDER BY RANDOM() LIMIT 3;"; // 무작위로 3행 회사명, 공고 제목, 접수 마감일 읽는 쿼리문
    string normal_serach_sentence; // 일반 검색(모든 열) 조합 string 쿼리문
    string n_serach_sentence = "SELECT company_num, loc, edu, co_size, co_name, notice_title, duty, working_date, intake, co_addr, est_date, biz_cat, biz_content FROM Company_Info WHERE "
    "loc || edu || co_size || co_name || notice_title || duty || working_date || intake || co_addr || est_date || biz_cat || biz_content LIKE '%"; // 일반 검색 쿼리문
    string like_end = "%'"; // LIKE 맺음 쿼리문
    string detail_search_sentence; // 상세 검색(근무 지역, 학력, 기업 규모 일치) 조합 string 쿼리문
    string d_search_sentence_01 = "SELECT company_num, loc, edu, co_size, co_name, notice_title, duty, working_date, intake, co_addr, est_date, biz_cat, biz_content FROM Company_Info WHERE "
    "loc == '"; // 상세 검색 쿼리문 01
    string d_search_sentence_and = "' AND "; // 상세 검색 쿼리문 AND
    string d_search_sentence_02 = "edu == '"; // 상세 검색 쿼리문 02
    string d_search_sentence_03 = "co_size == '"; // 상세 검색 쿼리문 03
    string d_sentence_end = "';"; // 상세 검색, 공고 상세, 기업 정보 쿼리문 END
    string detail_notice_sentence; // 공고 상세 조합 string 쿼리문
    string d_notice_sentence = "SELECT notice_title, co_name, deadline, duty, working_date, intake, notice_addr FROM Company_Info WHERE company_num == '"; // 공고 상세 쿼리문
    string company_info_sentence; // 기업 정보 조합 string 쿼리문
    string c_info_sentence = "SELECT co_site, co_addr, CEO_name, est_date, employee_num, revenue, biz_cat, biz_content FROM Company_Info WHERE company_num == '"; // 기업 정보 쿼리문
}query;

struct enter_key // 엔터키 위한 구조체
{
    char ter; // 엔터키
}en;

struct login_user_info // 로그인(입력) 유저 구조체
{
    string id; // 아이디
    string pin_code; // 핀 번호
    int judge = 0; // 로그인 상태 확인 값
}login;

struct Company_Info // 회사 정보 DB값 구조체
{
    const unsigned char* loc; // 근무 지역
    const unsigned char* edu; // 학력
    const unsigned char* co_size; // 기업 규모
    const unsigned char* co_name; // 회사명
    const unsigned char* notice_title; // 공고 제목
    const unsigned char* deadline; // 접수 마감일
    const unsigned char* duty; // 담당업무
    const unsigned char* working_date; // 근무 일시
    const unsigned char* intake; // 채용인원
    const unsigned char* notice_addr; // 공고 사이트 주소
    const unsigned char* co_site; // 회사 홈페이지
    const unsigned char* co_addr; // 회사 주소
    const unsigned char* CEO_name; // 대표자명
    const unsigned char* est_date; // 설립일(연차)
    const unsigned char* employee_num; // 사원 수
    const unsigned char* revenue; // 매출액
    const unsigned char* biz_cat; // 업종
    const unsigned char* biz_content; // 사업 내용
    int company_num; // 회사 순번
}co;

struct etc // 기타 구조체
{
    int i = 0; // 회사 출력 제한 위한 값
    int j = 0; // 검색 건수 출력을 위한 값
}etc;

struct serach // 검색 구조체
{
    int search = 0; // 검색 옵션 정수
    string keyword; // 검색어
    int result = 0; // 기본 검색, 상세 검색 끝내기 위한 값
    int detail_num = 0; // 상세 검색 옵션 정수
    int detail_loc_num = 0; // 상세 검색 - 지역 옵션 정수
    string detail_loc; // 상세 검색 - 지역
    int detail_edu_num = 0; // 상세 검색 - 학력 옵션 정수
    string detail_edu; // 상세 검색 - 학력
    int detail_co_size_num = 0; // 상세 검색 - 기업 규모 옵션 정수
    string detail_co_size; // 상세 검색 - 기업 규모
    int res_com_num[80]; // 검색 결과의 회사 순번 받는 배열
    int* res_p; // 검색 결과 회사 순번 find 포인터
    int result_num = 0; // 상세히 볼 기업 번호 선택
}srch;

class detail_srch_if // 상세 검색 - 지역 선택 클래스
{
    public:
    string loc_if(int loc_num); // 입력 숫자에 맞는 지역 출력, 반환하는 멤버 함수
    string edu_if(int edu_num); // 입력 숫자에 맞는 학력 출력, 반환하는 멤버 함수
    string co_size_if(int co_size_num); // 입력 숫자에 맞는 학력 출력, 반환하는 멤버 함수
};

int main() // 메인 함수
{
    detail_srch_if d_srch; // 상세 검색 - 지역 선택 클래스 객체 선언
    
    while(1) // 취업in 시작
    {
        system("clear"); // 터미널 비움
        ui.select = 0; // 옵션 초기화
        ui.exit = 0; // 나가기 초기화
        
        ifstream logo("txt_file/logo.txt"); // 로고 파일을 프로그램에 입력
        if(!logo.is_open())
        {
            cout << "로고 파일을 찾을 수 없습니다." << endl;
        } // 로고 파일 못 찾을 시 문구 출력

        while(logo)
        {
            getline(logo, p.rint);
            cout << p.rint << endl;
        } // 로고 파일을 문자열 rint에 넣어 출력
        logo.close(); // 로고 파일 닫음

        cout << endl; // 로고와 한 줄 띄움
        cout << "취업in에 방문하신 여러분을 환영합니다!" << endl; // 환영 문구 출력
        cout << "1. 회원가입 2. 로그인" << endl;
        cout << "선택하실 옵션을 입력해 주세요: ";
        cin >> ui.select; // 옵션값 입력
        
        while(1) // 선택한 옵션 입력값 오류 판단
        {
            if(ui.select == 1 || ui.select == 2) // 선택한 옵션 입력값이 맞을 때 | while 문 나가지 못함을 방지
            {
                break; // 오류 아닐 때 진행하기 위해 나감
            }
            else // 선택한 옵션 입력값이 틀릴 때
            {
                cout << "잘못된 입력입니다! 다시 입력해 주세요!" << endl;
                sleep(1); // 오류를 읽기 위한 대기
                cin.clear(); // cin(입력 스트림) 상태 플래그 초기화 | 다음 입력이 정상적으로 수행하게 함
                cin.ignore(100, '\n'); // 입력 스트림 문자 무시, 버퍼 비움 | 최대 100개의 문자 무시하다가 \n(엔터)가 나오면 멈춤
                system("clear");
                break;
            }
        }

        while(ui.select == 1) // 회원가입을 선택한 경우
        {
            if(ui.exit == 1) // 나가기 구문
            {
                break;
            }

            system("clear");
            cout << "회원가입 페이지입니다!" << endl;
            cout << "아이디를 입력해 주세요: ";
            cin >> join.id;

            sqlite3* join_id_db; // 데이터베이스 연결할 변수
            sqlite3_stmt* join_id_db_query; // 쿼리문을 실행할 객체

            int join_id_db_open = sqlite3_open("db/get_job_in_database", &join_id_db); // 멤버 데이터베이스를 엶
            if(join_id_db_open != SQLITE_OK) // 열기에 실패할 때
            {
                cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(join_id_db) << endl;// 에러 메시지 반환
                sqlite3_close(join_id_db); // 데이터베이스 파일 닫음

                return 1; // 종료
            }

            join_id_db_open = sqlite3_prepare_v2(join_id_db, query.check_id.c_str(), -1, &join_id_db_query, 0); // 아이디 확인 쿼리문 준비
            if(join_id_db_open != SQLITE_OK) // 쿼리가 실패할 때
            {
                cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(join_id_db) << endl;
                sqlite3_close(join_id_db);
                
                return 1;
            }

            while(join_id_db_open = sqlite3_step(join_id_db_query) == SQLITE_ROW) // 준비된 쿼리문을 실행하고 더 이상 행이 없을 때까지
            {
                join.id_judge = 0; // 오류값 초기화
                user.id = sqlite3_column_text(join_id_db_query, 0); // 첫 열 확인

                if(join.id == (string)(const char*)user.id) // 가입할 아이디와 저장된 아이디가 같을 때
                {
                    cout << "중복입니다! 다시 입력해 주세요!" << endl;
                    sleep(1);
                    join.id_judge++; // 오류 이므로 +1
                    break;
                }
            }
            sqlite3_finalize(join_id_db_query); // stmt(쿼리문) 정리(삭제)
            sqlite3_close(join_id_db); // 데이터베이스 닫기

            while(join.id_judge == 0) // 아이디 오류가 없을 동안
            {
                system("clear");
                cout << "아이디: " << join.id << endl;
                cout << "핀 번호를 입력해 주세요." << endl;
                cout << "핀 번호는 4자리 숫자만 가능합니다." << endl;
                cout << "____\b\b\b\b"; // 핀 번호 입력 시 빈칸(_) 표기 및 입력 시 지워짐 효과
                cin >> join.pin_code;
                try // 핀 번호 입력 예외 처리
                {
                    if(join.pin_code.length() == 4 && stoi(join.pin_code) < 10000 && stoi(join.pin_code) > -1) // 4자리, 0이상 9999이하일 때
                    {
                        break;
                    }
                    else // 바로 위의 if에 해당하지 않을 때(범위 미 해당)
                    {
                        cout << "올바르지 않은 입력입니다!" << endl;
                        join.pin_code.erase(0, 100);
                        sleep(1);
                        system("clear");
                    }
                }
                catch(std::invalid_argument&) // 위의 if에 해당하지 않고 std::invalid_argument&(stoi에 문자값일 때) 오류일 때
                {
                    cout << "올바르지 않은 입력입니다!" << endl;
                    join.pin_code.erase(0, 100);
                    sleep(1);
                    system("clear");
                }
            } // while(join.id_judge == 0) // 아이디 오류가 없을 동안

            while(join.id_judge == 0 && join.pin_judge == 0) // 아이디, 핀 번호 오류가 없을 동안
            {
                if(ui.exit == 1)
                {
                    break;
                }

                system("clear");
                cout << "아이디: " << join.id << " 핀 번호: " << join.pin_code << endl;
                cout << "이메일을 입력해 주세요." << endl;
                cin >> join.email;
                sqlite3* join_email_db;
                sqlite3_stmt* join_email_db_query;

                int join_email_db_open = sqlite3_open("db/get_job_in_database", &join_email_db);
                if(join_email_db_open != SQLITE_OK)
                {
                    cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(join_email_db) << endl;
                    sqlite3_close(join_email_db);

                    return 1;
                }

                join_email_db_open = sqlite3_prepare_v2(join_email_db, query.check_email.c_str(), -1, &join_email_db_query, 0);
                if(join_email_db_open != SQLITE_OK)
                {
                    cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(join_email_db) << endl;
                    sqlite3_close(join_email_db);
                    
                    return 1;
                }

                while(join_email_db_open = sqlite3_step(join_email_db_query) == SQLITE_ROW)
                {
                    join.email_judge = 0;
                    user.email = sqlite3_column_text(join_email_db_query, 0);

                    if(join.email == (string)(const char*)user.email)
                    {
                        cout << "중복입니다! 다시 입력해 주세요!" << endl;
                        sleep(1);
                        join.email_judge++;
                        system("clear");
                        break;
                    }
                }
                sqlite3_finalize(join_email_db_query);
                sqlite3_close(join_email_db);

                while(join.id_judge == 0 && join.pin_judge == 0 && join.email_judge == 0) // 아이디, 핀 번호, 이메일 오류가 없을 동안
                {
                    if(ui.exit == 1)
                    {
                        break;
                    }

                    system("clear");
                    cout << "아이디: " << join.id << " 핀 번호: " << join.pin_code << endl;
                    cout << "이메일: " << join.email << endl;
                    cout << "휴대전화 번호를 입력해 주세요.('-'제외)" << endl;
                    cout << "___________\b\b\b\b\b\b\b\b\b\b\b";
                    cin >> join.phnum;
                    try // 휴대전화 번호 예외 처리
                    {
                        if(join.phnum.length() == 11 && stoi(join.phnum) > 999999999 && stoi(join.phnum) < 1100000000)
                        {
                            sqlite3* join_phnum_db;
                            sqlite3_stmt* join_phnum_db_query;

                            int join_phnum_db_open = sqlite3_open("db/get_job_in_database", &join_phnum_db);
                            if(join_phnum_db_open != SQLITE_OK)
                            {
                                cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(join_phnum_db) << endl;
                                sqlite3_close(join_phnum_db);

                                return 1;
                            }

                            join_phnum_db_open = sqlite3_prepare_v2(join_phnum_db, query.check_phnum.c_str(), -1, &join_phnum_db_query, 0);
                            if(join_phnum_db_open != SQLITE_OK)
                            {
                                cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(join_phnum_db) << endl;
                                sqlite3_close(join_phnum_db);
                                
                                return 1;
                            }

                            while(join_phnum_db_open = sqlite3_step(join_phnum_db_query) == SQLITE_ROW)
                            {
                                join.phnum_judge = 0;
                                user.phnum = sqlite3_column_text(join_phnum_db_query, 0);

                                if(join.phnum == (string)(const char*)user.phnum)
                                {
                                    cout << "중복입니다! 다시 입력해 주세요!" << endl;
                                    sleep(1);
                                    join.phnum_judge++;
                                    system("clear");
                                    break;
                                }
                            }
                            sqlite3_finalize(join_phnum_db_query);
                            sqlite3_close(join_phnum_db);

                            while(join.id_judge == 0 && join.pin_judge == 0 && join.email_judge == 0 && join.phnum_judge == 0)  // 아이디, 핀 번호, 이메일, 휴대전화 번호가 오류가 없을 동안
                            {
                                system("clear");
                                cout << "회원가입이 완료되었습니다!" << endl;
                                cout << "회원님의 아이디는 " << join.id << " 핀 번호는 " << join.pin_code << endl << "이메일은 " << join.email << " 휴대전화 번호는 " << join.phnum << "입니다." << endl;
                                sleep(5);
                                cout << "확인이 끝나셨다면 enter를 눌러주세요.";
                                cin.get(en.ter); // 엔터키를 받기
                                cin.ignore(100,'\n'); // 엔터키 전의 입력값은 무시
                                if(en.ter == '\n')
                                {    
                                    sqlite3* join_db;
                                    sqlite3_stmt* join_db_query;

                                    int join_db_open = sqlite3_open("db/get_job_in_database", &join_db);
                                    if(join_db_open != SQLITE_OK)
                                    {
                                        cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(join_db) << endl;
                                        sqlite3_close(join_db);

                                        return 1;
                                    }
                                    query.all_insert_sentence = query.insert_all + join.id + "', '" + join.pin_code + "', '" + join.email + "', '" + join.phnum + "'" + query.end;

                                    join_db_open = sqlite3_prepare_v2(join_db, query.all_insert_sentence.c_str(), -1, &join_db_query, 0);
                                    if(join_db_open != SQLITE_OK)
                                    {
                                        cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(join_db) << endl;
                                        sqlite3_close(join_db);
                                        
                                        return 1;
                                    }

                                    while(join_db_open = sqlite3_step(join_db_query) == SQLITE_ROW)
                                    {
                                        user.id = sqlite3_column_text(join_db_query, 0); // 첫 열에 넣기
                                        user.pin_code = sqlite3_column_text(join_db_query, 1); // 두 번째 열에 넣기
                                        user.email = sqlite3_column_text(join_db_query, 2); // 세 번째 열에 넣기
                                        user.phnum = sqlite3_column_text(join_db_query, 3); // 네 번째 열에 넣기
                                    }
                                    sqlite3_finalize(join_db_query);
                                    sqlite3_close(join_db);

                                    sqlite3* join_usernum_db;
                                    sqlite3_stmt* join_usernum_db_query;

                                    int join_usernum_db_open = sqlite3_open("db/get_job_in_database", &join_usernum_db);
                                    if(join_usernum_db_open != SQLITE_OK)
                                    {
                                        cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(join_usernum_db) << endl;
                                        sqlite3_close(join_usernum_db);

                                        return 1;
                                    }

                                    join_usernum_db_open = sqlite3_prepare_v2(join_usernum_db, query.check_usernum.c_str(), -1, &join_usernum_db_query, 0);
                                    if(join_usernum_db_open != SQLITE_OK)
                                    {
                                        cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(join_usernum_db) << endl;
                                        sqlite3_close(join_usernum_db);
                                                                                
                                        return 1;
                                    }

                                    while(join_usernum_db_open = sqlite3_step(join_usernum_db_query) == SQLITE_ROW)
                                    {
                                        user.usernum = sqlite3_column_text(join_usernum_db_query, 0);
                                        join.usernum = (string)(const char*)user.usernum;
                                    }
                                    sqlite3_finalize(join_usernum_db_query);
                                    sqlite3_close(join_usernum_db);
                                    cout << "회원님의 번호는 " << join.usernum << "번입니다." << endl;
                                    sleep(3);

                                    ui.exit++;
                                    break;
                                } // if(en.ter == '\n')

                            } // while(join.id_judge == 0 && join.pin_judge == 0 && join.email_judge == 0 && join.phnum_judge == 0)  // 아이디, 핀 번호, 이메일, 휴대전화 번호가 오류가 없을 동안
                        
                        } // if(join.phnum.length() == 11 && stoi(join.phnum) > 999999999 && stoi(join.phnum) < 1100000000)
                        else
                        {
                            cout << "올바르지 않은 입력입니다!" << endl;
                            join.phnum.erase(0, 100);
                            sleep(1);
                            system("clear");
                        }

                    } // try // 휴대전화 번호 예외 처리

                    catch(std::invalid_argument&)
                    {
                        cout << "올바르지 않은 입력입니다!" << endl;
                        join.phnum.erase(0, 100);
                        sleep(1);
                        system("clear");
                    }
                    catch(std::out_of_range&)
                    {
                        cout << "올바르지 않은 입력입니다!" << endl;
                        join.phnum.erase(0, 100);
                        sleep(1);
                        system("clear");
                    } // try // 휴대전화 번호 예외 처리 catch문 마무리

                } // while(join.id_judge == 0 && join.pin_judge == 0 && join.email_judge == 0) // 아이디, 핀 번호, 이메일 오류가 없을 동안

            } // while(join.id_judge == 0 && join.pin_judge == 0) // 아이디, 핀 번호 오류가 없을 동안

        } // while(ui.select == 1) // 회원가입을 선택한 경우

        while(ui.select == 2)
        {
            ui.select = 0; // 옵션 초기화
            ui.exit = 0; // 나가기 초기화
            login.judge  = 0; // 로그인 상태 확인 초기화
            srch.search = 0; // 검색 옵션 정수 초기화
            srch.result = 0; // 기본 검색, 상세 검색 끝내기 위한 값 초기화
            fill(srch.res_com_num, srch.res_com_num + 80, 0); // 검색 결과의 회사 순번 받는 배열 
            etc.j = 0; // 검색 건수 값 초기화

            while(login.judge == 0) // 미 로그인 동안
            {
                system("clear");
                cout << "로그인 페이지입니다!" << endl;
                cout << "아이디를 입력: ";
                cin >> login.id;
                cout << "핀 번호를 입력: ";
                cin >> login.pin_code;
                
                sqlite3* join_db;
                sqlite3_stmt* join_db_query;

                int join_db_open = sqlite3_open("db/get_job_in_database", &join_db);
                if(join_db_open != SQLITE_OK)
                {
                    cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(join_db) << endl;
                    sqlite3_close(join_db);

                    return 1;
                }

                join_db_open = sqlite3_prepare_v2(join_db, query.read_user_sentence.c_str(), -1, &join_db_query, 0);
                if(join_db_open != SQLITE_OK)
                {
                    cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(join_db) << endl;
                    sqlite3_close(join_db);
                    
                    return 1;
                }

                while(join_db_open = sqlite3_step(join_db_query) == SQLITE_ROW)
                {
                    system("clear");
                    user.id = sqlite3_column_text(join_db_query, 0);
                    user.pin_code = sqlite3_column_text(join_db_query, 1);
                    if((string)(const char*)user.id == login.id && (string)(const char*)user.pin_code == login.pin_code)
                    {
                        login.judge++;
                        break;
                    }
                }
                if(login.judge == 0)
                {
                    cout << "아이디나 핀 번호가 틀렸습니다!" << endl;
                    cout << "다시 입력해 주세요." << endl;
                    sleep(1);
                }
                sqlite3_finalize(join_db_query);
                sqlite3_close(join_db);
            } // while(login.judge == 0) // 미 로그인 동안

            while(login.judge == 1) // 로그인 동안
            {
                if(ui.exit == 1)
                {
                    break;
                }
                
                sqlite3* rand_company_db;
                sqlite3_stmt* rand_company_db_query;

                int rand_company_db_open = sqlite3_open("db/get_job_in_database", &rand_company_db);
                if(rand_company_db_open != SQLITE_OK)
                {
                    cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(rand_company_db) << endl;
                    sqlite3_close(rand_company_db);

                    return 1;
                }

                rand_company_db_open = sqlite3_prepare_v2(rand_company_db, query.read_rand_company_sentence.c_str(), -1, &rand_company_db_query, 0);
                if(rand_company_db_open != SQLITE_OK)
                {
                    cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(rand_company_db) << endl;
                    sqlite3_close(rand_company_db);
                    
                    return 1;
                }
                system("clear");

                while(rand_company_db_open = sqlite3_step(rand_company_db_query) == SQLITE_ROW && etc.i < 4)
                {
                    co.co_name = sqlite3_column_text(rand_company_db_query, 0);
                    co.notice_title = sqlite3_column_text(rand_company_db_query, 1);
                    co.deadline = sqlite3_column_text(rand_company_db_query, 2);
                    cout << "회사명: " << co.co_name << endl << "공고 제목: " << co.notice_title << endl <<  "접수 마감일: " << co.deadline << endl;
                    cout << endl;
                    etc.i++;
                }
                etc.i = 0;
                sqlite3_finalize(rand_company_db_query);
                sqlite3_close(rand_company_db);

                cout << "로그인되었습니다! 환영합니다. " << login.id << "님!" << endl;

                while(1) // 로그인 유지
                {
                    if(ui.exit == 1)
                    {
                        break;
                    }

                    sqlite3* rand_company_db;
                    sqlite3_stmt* rand_company_db_query;

                    int rand_company_db_open = sqlite3_open("db/get_job_in_database", &rand_company_db);
                    if(rand_company_db_open != SQLITE_OK)
                    {
                        cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(rand_company_db) << endl;
                        sqlite3_close(rand_company_db);

                        return 1;
                    }

                    rand_company_db_open = sqlite3_prepare_v2(rand_company_db, query.read_rand_company_sentence.c_str(), -1, &rand_company_db_query, 0);
                    if(rand_company_db_open != SQLITE_OK)
                    {
                        cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(rand_company_db) << endl;
                        sqlite3_close(rand_company_db);
                        
                        return 1;
                    }
                    system("clear");

                    while(rand_company_db_open = sqlite3_step(rand_company_db_query) == SQLITE_ROW && etc.i < 4)
                    {
                        co.co_name = sqlite3_column_text(rand_company_db_query, 0);
                        co.notice_title = sqlite3_column_text(rand_company_db_query, 1);
                        co.deadline = sqlite3_column_text(rand_company_db_query, 2);
                        cout << "회사명: " << co.co_name << endl << "공고 제목: " << co.notice_title << endl <<  "접수 마감일: " << co.deadline << endl;
                        cout << endl;
                        etc.i++;
                    }
                    etc.i = 0;
                    sqlite3_finalize(rand_company_db_query);
                    sqlite3_close(rand_company_db);

                    cout << "선택하실 검색 옵션(번호만)을 입력해 주세요." << endl;
                    cout << "1. 기본 검색 2. 상세 검색: ";
                    cin >> srch.search;

                    while(1)
                    {
                        if(srch.search == 1 || srch.search == 2)
                        {
                            break;
                        }
                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요!" << endl;
                            sleep(1);
                            cin.clear();
                            cin.ignore(100, '\n');
                            system("clear");
                            break;
                        }
                    }

                    while(srch.search == 1) // 기본 검색
                    {
                        system("clear");
                        cout << endl;
                        cout << "기본 검색 페이지입니다." << endl;
                        cout << "검색: ";
                        cin >> srch.keyword;
                        if(srch.keyword.length() > 0)
                        {
                            srch.result++; // 검색 결과로 넘어가기 위한 값
                            break;
                        }
                    }

                    while(srch.search == 2) // 상세 검색
                    {   
                        system("clear");
                        if(srch.detail_loc.length() > 0 && srch.detail_edu.length() > 0 && srch.detail_co_size.length() > 0) // 전부 선택했을 때(전원 선택하여 길이가 0 이상일 때)
                        {
                            srch.result++;
                            break;
                        }

                        cout << "상세 검색 페이지입니다." << endl;
                        cout << "선택하신 근무 지역: " << srch.detail_loc << ", 선택하신 학력: " << srch.detail_edu << ", 선택하신 기업 규모: " << srch.detail_co_size << endl;
                        cout << "옵션을 골라주세요." << endl;
                        cout << "1. 근무 지역 2. 학력 3. 기업 규모"<< endl;
                        cin >> srch.detail_num;

                        if(srch.detail_num == 1) // 상세 검색 - 근무 지역
                        {   
                            system("clear");
                            cout << "원하시는 근무 지역을 골라주세요." << endl;
                            cout << "1. 경기도 고양 2. 경기도 과천 3. 경기도 광주 4. 경기도 군포 5. 경기도 부천 6. 경기도 성남 7. 경기도 수원 8. 경기도 안양 9. 경기도 용인" << endl;
                            cout << "10. 경기도 의왕 11. 경기도 전지역 12. 경기도 파주 13. 경기도 평택 14. 경기도 화성 15. 서울 강남구 16. 서울 강서구 17. 서울 구로구 18. 서울 금천구" << endl;
                            cout << "19. 서울 금초구 20. 서울 마포구 21. 서울 서대문구 22. 서울 서초구 23. 서울 성동구 24. 서울 송파구 25. 서울 영등포구 26. 인천 연수구 27. 인천 전지역" << endl;
                            cout << "입력: ";
                            cin >> srch.detail_loc_num;
                            while(1) // srch.detail_loc_num 정상 입력 판단
                            {
                                if(srch.detail_loc_num > 0 && srch.detail_loc_num < 28)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "잘못된 입력입니다! 다시 입력해 주세요!" << endl;
                                    sleep(1);
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                    system("clear");
                                    break;
                                }
                            }
                            srch.detail_loc = d_srch.loc_if(srch.detail_loc_num);

                        } // if(srch.detail_num == 1) // 상세 검색 - 근무 지역

                        else if(srch.detail_num == 2) // 상세 검색 - 학력
                        {
                            system("clear");
                            cout << "원하시는 학력을 골라주세요." << endl;
                            cout << "1. 학력 무관 2. 초대졸 이상 3. 대졸 4. 대졸 이상" << endl;
                            cout << "입력: ";
                            cin >> srch.detail_edu_num;
                            while(1) // srch.detail_edu_num 정상 입력 판단
                            {
                                if(srch.detail_edu_num > 0 && srch.detail_edu_num < 5)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "잘못된 입력입니다! 다시 입력해 주세요!" << endl;
                                    sleep(1);
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                    system("clear");
                                    break;
                                }
                            }
                            srch.detail_edu = d_srch.edu_if(srch.detail_edu_num);
                        }

                        else if(srch.detail_num == 3) // 상세 검색 - 기업 규모
                        {
                            system("clear");
                            cout << "원하시는 기업 규모를 골라주세요." << endl;
                            cout << "1. 벤처기업 2. 스타트업 3. 중소기업 4. 코스닥 상장 기업" << endl;
                            cout << "입력: ";
                            cin >> srch.detail_co_size_num;
                            while(1) // srch.detail_edu_num 정상 입력 판단
                            {
                                if(srch.detail_co_size_num > 0 && srch.detail_co_size_num < 5)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "잘못된 입력입니다! 다시 입력해 주세요!" << endl;
                                    sleep(1);
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                    system("clear");
                                    break;
                                }
                            }
                            srch.detail_co_size = d_srch.co_size_if(srch.detail_co_size_num);
                        }

                        else
                        {
                            cout << "잘못된 입력입니다! 다시 입력해 주세요!" << endl;
                            sleep(1);
                            cin.clear();
                            cin.ignore(100, '\n');
                            system("clear");
                        }

                    } // while(srch.search == 2) // 상세 검색

                    while(srch.result == 1) // 검색 결과
                    {
                        if(srch.keyword.length() > 0) // 일반 검색
                        {
                            sqlite3* normal_search_db;
                            sqlite3_stmt* normal_search_db_query;

                            int normal_search_db_open = sqlite3_open("db/get_job_in_database", &normal_search_db);
                            if(normal_search_db_open != SQLITE_OK)
                            {
                                cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(normal_search_db) << endl;
                                sqlite3_close(normal_search_db);

                                return 1;
                            }
                            query.normal_serach_sentence = query.n_serach_sentence + srch.keyword + query.like_end;

                            normal_search_db_open = sqlite3_prepare_v2(normal_search_db, query.normal_serach_sentence.c_str(), -1, &normal_search_db_query, 0);
                            if(normal_search_db_open != SQLITE_OK)
                            {
                                cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(normal_search_db) << endl;
                                sqlite3_close(normal_search_db);
                                
                                return 1;
                            }
                            system("clear");

                            while(normal_search_db_open = sqlite3_step(normal_search_db_query) == SQLITE_ROW)
                            {
                                co.company_num = sqlite3_column_int(normal_search_db_query, 0);
                                co.loc = sqlite3_column_text(normal_search_db_query, 1);
                                co.edu = sqlite3_column_text(normal_search_db_query, 2);
                                co.co_size = sqlite3_column_text(normal_search_db_query, 3);
                                co.co_name = sqlite3_column_text(normal_search_db_query, 4);
                                co.notice_title = sqlite3_column_text(normal_search_db_query, 5);
                                co.duty = sqlite3_column_text(normal_search_db_query, 6);
                                co.working_date = sqlite3_column_text(normal_search_db_query, 7);
                                co.intake = sqlite3_column_text(normal_search_db_query, 8);
                                co.co_addr = sqlite3_column_text(normal_search_db_query, 9);
                                co.est_date = sqlite3_column_text(normal_search_db_query, 10);
                                co.biz_cat = sqlite3_column_text(normal_search_db_query, 11);
                                co.biz_content = sqlite3_column_text(normal_search_db_query, 12);
                                cout << "회사 순번: " << co.company_num << endl;
                                cout << endl;
                                cout << "근무 지역: " << co.loc << endl << "학력: " << co.edu << endl << "기업 규모: " << co.co_size << endl << "회사명: " << co.co_name << endl
                                << "공고 제목: " << co.notice_title << endl << "담당업무: " << co.duty << endl << "근무 일시: " << co.working_date << endl << "채용인원: " << co.intake << endl
                                << "회사 주소: " << co.co_addr << endl << "설립일(연차): " << co.est_date << endl << "업종: " << co.biz_cat << endl << "사업 내용: " << co.biz_content << endl;
                                cout << endl;

                                srch.res_com_num[etc.j] = co.company_num; // 검색한 순번 넣기 위한 배열
                                etc.j++; // 검색한 건수 세기 위한 정수
                            }
                            srch.keyword.erase(0, 100); // while(srch.result == 1) // 검색 결과로 검색 결과가 반복하고 있으므로 지우지 않는 이상 계속 출력
                            sqlite3_finalize(normal_search_db_query);
                            sqlite3_close(normal_search_db);
                        } // if(srch.keyword.length() > 0) // 일반 검색

                        else if(srch.detail_loc.length() > 0 && srch.detail_edu.length() > 0 && srch.detail_co_size.length() > 0) // 상세 검색
                        {
                            sqlite3* detail_search_db;
                            sqlite3_stmt* detail_search_db_query;

                            int detail_search_db_open = sqlite3_open("db/get_job_in_database", &detail_search_db);
                            if(detail_search_db_open != SQLITE_OK)
                            {
                                cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(detail_search_db) << endl;
                                sqlite3_close(detail_search_db);

                                return 1;
                            }
                            query.detail_search_sentence = query.d_search_sentence_01 + srch.detail_loc + query.d_search_sentence_and + query.d_search_sentence_02 + srch.detail_edu + 
                            query.d_search_sentence_and + query.d_search_sentence_03 + srch.detail_co_size + query.d_sentence_end;
                            
                            detail_search_db_open = sqlite3_prepare_v2(detail_search_db, query.detail_search_sentence.c_str(), -1, &detail_search_db_query, 0);
                            if(detail_search_db_open != SQLITE_OK)
                            {
                                cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(detail_search_db) << endl;
                                sqlite3_close(detail_search_db);
                                
                                return 1;
                            }
                            system("clear");

                            while(detail_search_db_open = sqlite3_step(detail_search_db_query) == SQLITE_ROW)
                            {
                                co.company_num = sqlite3_column_int(detail_search_db_query, 0);
                                co.loc = sqlite3_column_text(detail_search_db_query, 1);
                                co.edu = sqlite3_column_text(detail_search_db_query, 2);
                                co.co_size = sqlite3_column_text(detail_search_db_query, 3);
                                co.co_name = sqlite3_column_text(detail_search_db_query, 4);
                                co.notice_title = sqlite3_column_text(detail_search_db_query, 5);
                                co.duty = sqlite3_column_text(detail_search_db_query, 6);
                                co.working_date = sqlite3_column_text(detail_search_db_query, 7);
                                co.intake = sqlite3_column_text(detail_search_db_query, 8);
                                co.co_addr = sqlite3_column_text(detail_search_db_query, 9);
                                co.est_date = sqlite3_column_text(detail_search_db_query, 10);
                                co.biz_cat = sqlite3_column_text(detail_search_db_query, 11);
                                co.biz_content = sqlite3_column_text(detail_search_db_query, 12);
                                cout << "회사 순번: " << co.company_num << endl;
                                cout << endl;
                                cout << "근무 지역: " << co.loc << endl << "학력: " << co.edu << endl << "기업 규모: " << co.co_size << endl << "회사명: " << co.co_name << endl
                                << "공고 제목: " << co.notice_title << endl << "담당업무: " << co.duty << endl << "근무 일시: " << co.working_date << endl << "채용인원: " << co.intake << endl
                                << "회사 주소: " << co.co_addr << endl << "설립일(연차): " << co.est_date << endl << "업종: " << co.biz_cat << endl << "사업 내용: " << co.biz_content << endl;
                                cout << endl;

                                srch.res_com_num[etc.j] = co.company_num; // 검색한 순번 넣기 위한 배열
                                etc.j++; // 검색한 건수 세기 위한 정수
                            }
                            srch.detail_loc.erase(0, 100); 
                            srch.detail_edu.erase(0, 100); 
                            srch.detail_co_size.erase(0, 100); // while(srch.result == 1) // 검색 결과로 검색 결과가 반복하고 있으므로 지우지 않는 이상 계속 출력
                            sqlite3_finalize(detail_search_db_query);
                            sqlite3_close(detail_search_db);
                        } // else if(srch.detail_loc.length() > 0 && srch.detail_edu.length() > 0 && srch.detail_co_size.length() > 0) // 상세 검색

                            if(etc.j > 0) // 검색 건수가 있을 때
                            {
                                cout << "검색 결과 " << etc.j << "건" << endl;
                                cout << "상세 공고를 볼 회사 순번을 입력해주세요: ";
                                cin >> srch.result_num;
                            
                                srch.res_p = find(srch.res_com_num, srch.res_com_num + 80, srch.result_num); // 순번이 배열에 있는지 판단
                                if(srch.res_p != srch.res_com_num + 80) // 순번이 배열에 있을 때
                                {
                                    sqlite3* detail_notice_db;
                                    sqlite3_stmt* detail_notice_db_query;

                                    int detail_notice_db_open = sqlite3_open("db/get_job_in_database", &detail_notice_db);
                                    if(detail_notice_db_open != SQLITE_OK)
                                    {
                                        cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(detail_notice_db) << endl;
                                        sqlite3_close(detail_notice_db);

                                        return 1;
                                    }
                                    query.detail_notice_sentence = query.d_notice_sentence + to_string(srch.result_num) + query.d_sentence_end;

                                    detail_notice_db_open = sqlite3_prepare_v2(detail_notice_db, query.detail_notice_sentence.c_str(), -1, &detail_notice_db_query, 0);
                                    if(detail_notice_db_open != SQLITE_OK)
                                    {
                                        cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(detail_notice_db) << endl;
                                        sqlite3_close(detail_notice_db);
                                        
                                        return 1;
                                    }
                                    system("clear");
                                    
                                    while(detail_notice_db_open = sqlite3_step(detail_notice_db_query) == SQLITE_ROW)
                                    {
                                        co.notice_title = sqlite3_column_text(detail_notice_db_query, 0);
                                        co.co_name = sqlite3_column_text(detail_notice_db_query, 1);
                                        co.deadline = sqlite3_column_text(detail_notice_db_query, 2);
                                        co.duty = sqlite3_column_text(detail_notice_db_query, 3);
                                        co.working_date = sqlite3_column_text(detail_notice_db_query, 4);
                                        co.intake = sqlite3_column_text(detail_notice_db_query, 5);
                                        co.notice_addr =sqlite3_column_text(detail_notice_db_query, 6);
                                        cout << "공고 제목: " << co.notice_title << endl << "기업명: " << co.co_name << endl << "접수 마감일: " << co.deadline << endl
                                        << "담당업무: " << co.duty << endl << "근무일시: " << co.working_date << endl << "채용인원: " << co.intake << endl
                                        << "공고 사이트 주소: " << co.notice_addr << endl;
                                        cout << endl;
                                    }
                                    sqlite3_finalize(detail_notice_db_query);
                                    sqlite3_close(detail_notice_db);
                                
                                    cout << "계속해서 기업 정보를 보시려면 엔터를 눌러주세요" << endl;
                                    cin.get(en.ter);
                                    cin.ignore(100,'\n');
                                    if(en.ter == '\n')
                                    {   
                                        sqlite3* company_info_db;
                                        sqlite3_stmt* company_info_db_query;

                                        int company_info_db_open = sqlite3_open("db/get_job_in_database", &company_info_db);
                                        if(company_info_db_open != SQLITE_OK)
                                        {
                                            cerr << "회원 데이터베이스 파일 열기에 실패했습니다!" << sqlite3_errmsg(company_info_db) << endl;
                                            sqlite3_close(company_info_db);

                                            return 1;
                                        }
                                        query.company_info_sentence = query.c_info_sentence + to_string(srch.result_num) + query.d_sentence_end;

                                        company_info_db_open = sqlite3_prepare_v2(company_info_db, query.company_info_sentence.c_str(), -1, &company_info_db_query, 0);
                                        if(company_info_db_open != SQLITE_OK)
                                        {
                                            cerr << "입력 실행이 실패했습니다!" << sqlite3_errmsg(company_info_db) << endl;
                                            sqlite3_close(company_info_db);
                                            
                                            return 1;
                                        }
                                        system("clear");
                                        
                                        while(company_info_db_open = sqlite3_step(company_info_db_query) == SQLITE_ROW)
                                        {
                                            co.co_site = sqlite3_column_text(company_info_db_query, 0);
                                            co.co_addr = sqlite3_column_text(company_info_db_query, 1);
                                            co.est_date = sqlite3_column_text(company_info_db_query, 2);
                                            co.CEO_name = sqlite3_column_text(company_info_db_query, 3);
                                            co.employee_num = sqlite3_column_text(company_info_db_query, 4);
                                            co.revenue = sqlite3_column_text(company_info_db_query, 5);
                                            co.biz_cat = sqlite3_column_text(company_info_db_query, 6);
                                            co.biz_content =sqlite3_column_text(company_info_db_query, 7);
                                            cout << "회사 홈페이지: " << co.co_site << endl << "회사 주소: " << co.co_addr << endl << "대표자명: " << co.CEO_name << endl << "설립일(연차): " << co.est_date << endl
                                            << "사원 수: " << co.employee_num << endl << "매출액: " << co.revenue << endl << "업종: " << co.biz_cat << endl << "사업 내용: " << co.biz_content << endl;
                                            cout << endl;
                                        }
                                        sqlite3_finalize(company_info_db_query);
                                        sqlite3_close(company_info_db);
                                    }
                                    cout << "엔터를 누르면 처음으로 돌아갑니다." << endl;

                                    cin.ignore(100,'\n');
                                    if(en.ter == '\n')
                                    {   
                                        ui.exit++;
                                        break;
                                    }

                                } // if(srch.res_p != srch.res_com_num + 80) // 순번이 배열에 있을 때

                                else
                                {
                                    cout << "검색 결과에 없는 번호이거나 잘못된 입력입니다!" << endl;
                                    srch.result = 0;
                                    sleep(1);
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                }

                            } // while(etc.j > 0) // 검색 건수가 있을 때

                            if(etc.j == 0) // 검색 건수가 없을 때
                            {
                                cout << "검색 결과가 없습니다.." << endl;
                                srch.result = 0;
                                sleep(1);
                                system("clear");
                                break;
                            } // if(etc.j == 0) // 검색 건수가 없을 때
                        
                    } // while(srch.result == 1) // 검색 결과
                
                } // while(1) // 로그인 유지

            } // while(login.judge == 1) // 로그인 동안

        } // while(ui.select == 2)

    } // while(1) // 취업in 시작

    return 0;
} // int main() // 메인 함수

string detail_srch_if::loc_if(int loc_num)
{
    string location;
    switch(loc_num)
    {
        case 1:
        {
            location = "경기도 고양";
            break;
        }
        
        case 2:
        {
            location = "경기도 과천";
            break;
        }

        case 3:
        {
            location = "경기도 광주";
            break;
        }
        
        case 4:
        {
            location = "경기도 군포";
            break;
        }

        case 5:
        {
            location = "경기도 부천";
            break;
        }

        case 6:
        {
            location = "경기도 성남";
            break;
        }

        case 7:
        {
            location = "경기도 수원";
            break;
        }

        case 8:
        {
            location = "경기도 안양";
            break;
        }

        case 9:
        {
            location = "경기도 용인";
            break;
        }

        case 10:
        {
            location = "경기도 의왕";
            break;
        }

        case 11:
        {
            location = "경기도 전지역";
            break;
        }

        case 12:
        {
            location = "경기도 파주";
            break;
        }

        case 13:
        {
            location = "경기도 평택";
            break;
        }

        case 14:
        {
            location = "경기도 화성";
            break;
        }

        case 15:
        {
            location = "서울 강남구";
            break;
        }

        case 16:
        {
            location = "서울 강서구";
            break;
        }

        case 17:
        {
            location = "서울 구로구";
            break;
        }

        case 18:
        {
            location = "서울 금천구";
            break;
        }

        case 19:
        {
            location = "서울 금초구";
            break;
        }

        case 20:
        {
            location = "서울 마포구";
            break;
        }

        case 21:
        {
            location = "서울 서대문구";
            break;
        }

        case 22:
        {
            location = "서울 서초구";
            break;
        }

        case 23:
        {
            location = "서울 성동구";
            break;
        }

        case 24:
        {
            location = "서울 송파구";
            break;
        }

        case 25:
        {
            location = "서울 영등포구";
            break;
        }

        case 26:
        {
            location = "인천 연수구";
            break;
        }

        case 27:
        {
            location = "인천 전지역";
            break;
        }
    }

    return location;
}

string detail_srch_if::edu_if(int edu_num)
{
    string education;
    switch(edu_num)
    {
        case 1:
        {
            education = "학력 무관";
            break;
        }

        case 2:
        {
            education = "초대졸 이상";
            break;
        }

        case 3:
        {
            education = "대졸";
            break;
        }

        case 4:
        {
            education = "대졸 이상";
            break;
        }
    }

    return education;
}

string detail_srch_if::co_size_if(int co_size_num)
{
    string company_size;
    switch(co_size_num)
    {
        case 1:
        {
            company_size = "벤처기업";
            break;
        }

        case 2:
        {
            company_size = "스타트업";
            break;
        }

        case 3:
        {
            company_size = "중소기업";
            break;
        }

        case 4:
        {
            company_size = "코스닥 상장 기업";
            break;
        }
    }

    return company_size;
}