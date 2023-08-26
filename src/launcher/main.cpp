#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtGui/QIcon>
#include <QtCore/QProcess>
#include <QtGui/QPalette>
#include <QtGui/QPixmap>
#include <QtGui/QCursor>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow *window = new QMainWindow;
    window->setWindowTitle("Blade Launcher");

    QWidget *centralWidget = new QWidget(window);
    window->setCentralWidget(centralWidget);
    window->setFixedSize(800, 600);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QLabel *titleLabel = new QLabel("Blade Launcher");
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    titleLabel->setAlignment(Qt::AlignHCenter);
    mainLayout->addWidget(titleLabel);

    QLabel *descriptionLabel = new QLabel("Configurez les options de jeu ci-dessous avant de lancer le jeu.");
    descriptionLabel->setStyleSheet("font-size: 16px;");
    descriptionLabel->setAlignment(Qt::AlignHCenter);
    mainLayout->addWidget(descriptionLabel);

    QHBoxLayout *resolutionLayout = new QHBoxLayout;
    mainLayout->addLayout(resolutionLayout);

    QLabel *resolutionLabel = new QLabel("Résolution : ");
    resolutionLabel->setStyleSheet("font-size: 18px;");
    resolutionLayout->addWidget(resolutionLabel);

    QComboBox *resolutionComboBox = new QComboBox;
    resolutionComboBox->addItem("640x480");
    resolutionComboBox->addItem("800x600");
    resolutionComboBox->addItem("1024x768");
    resolutionComboBox->addItem("1280x720");
    resolutionComboBox->addItem("1366x768");
    resolutionComboBox->addItem("1920x1080");
    resolutionComboBox->setCursor(QCursor(Qt::PointingHandCursor));
    resolutionLayout->addWidget(resolutionComboBox);

    QHBoxLayout *audioLayout = new QHBoxLayout;
    mainLayout->addLayout(audioLayout);

    QLabel *audioLabel = new QLabel("Audio : ");
    audioLabel->setStyleSheet("font-size: 18px;");
    audioLayout->addWidget(audioLabel);

    QComboBox *audioComboBox = new QComboBox;
    audioComboBox->addItem("Désactivé");
    audioComboBox->addItem("Activé");
    audioComboBox->setCursor(QCursor(Qt::PointingHandCursor));
    audioLayout->addWidget(audioComboBox);

    QHBoxLayout *fullscreenLayout = new QHBoxLayout;
    mainLayout->addLayout(fullscreenLayout);

    QLabel *fullscreenLabel = new QLabel("Plein écran : ");
    fullscreenLabel->setStyleSheet("font-size: 18px;");
    fullscreenLayout->addWidget(fullscreenLabel);

    QComboBox *fullscreenComboBox = new QComboBox;
    fullscreenComboBox->addItem("Désactivé");
    fullscreenComboBox->addItem("Activé");
    fullscreenComboBox->setCursor(QCursor(Qt::PointingHandCursor));
    fullscreenLayout->addWidget(fullscreenComboBox);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    mainLayout->addLayout(buttonLayout);

    mainLayout->addSpacing(20);

    QPushButton *playButton = new QPushButton("Jouer");
    playButton->setStyleSheet("background-color: #4CAF50; color: white; border-radius: 5px; padding: 10px;");
    playButton->setFixedSize(780, 50);
    mainLayout->addWidget(playButton, 0, Qt::AlignLeft);

    mainLayout->addSpacing(8);

    playButton->setStyleSheet("QPushButton:hover { background-color: #2E7D32; }");

    QObject::connect(playButton, &QPushButton::clicked, [&]()
                     {
                         QString resolution = resolutionComboBox->currentText();
                         QString audio = audioComboBox->currentText();
                         QString fullscreen = fullscreenComboBox->currentText();

                         QFile configFile("game_config.txt");
                         if (configFile.open(QIODevice::WriteOnly | QIODevice::Text))
                         {
                             QTextStream out(&configFile);
                             out << "resolution:" << resolution << Qt::endl;
                             out << "audio:" << audio << Qt::endl;
                             out << "fullscreen:" << fullscreen << Qt::endl;
                             configFile.close();
                         }

                         QString executablePath = "./game.exe";

                     QProcess *process = new QProcess;
                     process->start(executablePath); 
                     QApplication::quit(); });

    window->show();

    return app.exec();
}
