#include <QCoreApplication>
#include "mp4parser.h"
#include "streamreader.h"
#include "streamwriter.h"

/// MVHD

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    //StreamReader reader("D:/asklab/video/video_2018_05_30_20-21-01.mp4");
    StreamReader reader("D:/vid.mp4");
    if (reader.openStream())
    {
        MP4Parser parser;
        parser.parse(reader);
        parser.prepareData(3,10);
        StreamWriter writer("D:/newfile.mp4");
        if(writer.openStream()){
            parser.writeOnlyVideo(reader,writer);
        }
    }
    return 0;//a.exec();
}
