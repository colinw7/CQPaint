#include <CQPaintTools.h>
#include <CQImageButton.h>
#include <CQWinWidget.h>
#include <QVBoxLayout>

#include <region_16_png.h>
#include <pen_16_png.h>
#include <color_picker_16_png.h>
#include <fill_16_png.h>
#include <close_16_png.h>

CQPaintToolsWindow::
CQPaintToolsWindow(QWidget *parent) :
 CQWinWidget(parent)
{
  setResizable(false);

  tools_ = new CQPaintTools;

  setChild(tools_);
}

CQPaintTools::
CQPaintTools(QWidget *parent) :
 QWidget(parent)
{
  select_button_  = new CQImageButton(region_data      , REGION_DATA_LEN      );
  pen_button_     = new CQImageButton(pen_data         , PEN_DATA_LEN         );
  dropper_button_ = new CQImageButton(color_picker_data, COLOR_PICKER_DATA_LEN);
  fill_button_    = new CQImageButton(fill_data        , FILL_DATA_LEN        );
  close_button_   = new CQImageButton(close_data       , CLOSE_DATA_LEN       );

  connect(select_button_ , SIGNAL(pressed()), this, SIGNAL(select ()));
  connect(pen_button_    , SIGNAL(pressed()), this, SIGNAL(pen    ()));
  connect(dropper_button_, SIGNAL(pressed()), this, SIGNAL(dropper()));
  connect(fill_button_   , SIGNAL(pressed()), this, SIGNAL(fill   ()));
  connect(close_button_  , SIGNAL(pressed()), this, SIGNAL(close  ()));

  layout_ = new QVBoxLayout;

  layout_->setMargin(2); layout_->setSpacing(2);

  layout_->addWidget(select_button_ );
  layout_->addWidget(pen_button_    );
  layout_->addWidget(dropper_button_);
  layout_->addWidget(fill_button_   );
  layout_->addWidget(close_button_  );

  layout_->addStretch(1);

  setLayout(layout_);
}

CQPaintTools::
~CQPaintTools()
{
}
