#include "../xstring.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <wchar.h>
void test_memory__allocate(int sz)
{
    while(sz-->0){
        xstring *s =xs_alloc(2000);
        FILE *f = fopen("/dev/random", "r");
        fgets(s->data, 2000, f);
        puts(s->data);
        xs_free(s);
    }


}
void test_memory__substring()
{
    xstring *t = xs_from_string(
        "Date: Wed, 03 Apr 2013 07:45:01 +0100\r\n"
        "To: <j.appleseed@me.com>\r\n"
        "From: <s@sevki.org>\r\n"
        "Subject: test Wed, 03 Apr 2013 07:45:01 +0100\r\n"
        "X-Mailer: %swaks% v20120320.0 jetmore.org/john/code/swaks/\r\n"
        "\r\n"
        "This is a test mailing\r\n"
        "\r\n"
        "\r\n.\r\n"
        "\r\n");
    xstring *p = xs_from_string("j.appleseed@me.com");
    xstring *r = xs_substr_btwn_chars(t,'<', '>');
    int z =memcmp(p->data, r->data, p->size);
    if(!z) puts("Substring between chars OK!");
    else exit(1);

    xstring *q = xs_substr_btwn_char(t,'%');
    z&=memcmp(q->data, "swaks", q->size);
    if(!z) puts("Substring between single char OK!");

    char *x =xs_find(t,xs_from_string("me"));
    if(x != NULL) puts("Find OK!");

    xs_replace(t, xs_from_string("sevki"), xs_from_string("me"));

    xs_replace(t, xs_from_string("swaks"), xs_from_string("schlong"));

    xs_cat(t, xs_from_string("the end"));
    assert(!z);
    puts(t->data);

}

int main()
{

    test_memory__allocate(20);
#ifdef __APPLE__
    // Becasue VALGRIND on OSX is retarted
    char com[20];
    sprintf (com, "leaks %d", getpid());
    puts("==START LEAKS==");
    system(com);
#endif
    puts("==START SUBSTRING==");
    test_memory__substring();
    return 0;
}
