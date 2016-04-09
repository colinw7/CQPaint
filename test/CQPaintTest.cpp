#include <CQApp.h>
#include <CQPaint.h>
#include <CQDirView.h>

int
main(int argc, char **argv)
{
  CQApp app(argc, argv);

  CQDirViewFactory::init();

  CQPaint paint;

  paint.init();

  if (argc > 1)
    paint.load(std::string(argv[1]));

  paint.show();

  return app.exec();
}
