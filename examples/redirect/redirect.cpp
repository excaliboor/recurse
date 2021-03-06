/*
*
* this is minimal hello world example
*/

#include "../../recurse.hpp"

int main(int argc, char *argv[])
{
    Recurse::Application app(argc, argv);

    app.use([](auto &ctx)
    {
        ctx.response.status(301).body("Redirecting...").redirect("http://www.google.com");
    });

    auto result = app.listen(3001);
    if (result.error())
    {
        qDebug() << "error upon listening:" << result.lastError();
    }
}
