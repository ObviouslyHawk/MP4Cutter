# MP4Cutter

## Общие сведения о MP4 

### Структура файла MP4

```
file.mp4    
└─ftyp
    ├─mdat
    └─moov
        ├─mvhd
        ├─trak
        │    ├─tkhd
        │    └─mdia
        │        ├─mdhd
        │        ├─hdlr
        │        └─minf
        │            ├─vmhd
        │            ├─dinf
        │            │    └─dref
        │            │        └─alis
        │            │
        │            └─stbl
        │                ├─stsc
        │                ├─stts
        │                ├─stsd
        │                │    └─avc1
        │                │        └─avcC
        │                │
        │                ├─stss
        │                ├─stco
        │                └─stsz
        │
        └─trak
            ├─tkhd
            └─mdia
                ├─mdhd
                ├─hdlr
                └─minf
                    ├─smhd
                    ├─dinf
                    │    └─dref
                    │        └─url
                    │
                    └─stbl
                        ├─stsd
                        │    └─mp4a
                        │        └─esds
                        │
                        ├─stts
                        ├─stsc
                        ├─stsz
                        └─stco
```

### Описание атомов

#### Общие

[**ftyp**](#paramftyp) *(file type)* — содержит тип файла и его совместимость. ***[копируем]*** \
[**mdat**](#parammdat) *(media data)* — содержит медиа данные. В видео треках, этот атом содержал бы кадры видео. Количество mdat атомов может быть от нуля и более. ***[парсим]*** \
[**moov**](#parammoov) *(movie box)* — содержит все метаданные по работе с mdat. \
[**mvhd**](#parammvhd) *(movie header)* — определяет общие параметры *(timescale, длительность наибольшего трека и т.д.)*.

#### Для видео

[**trak**](#paramtrak) *(track)* — содержит один трек презентации. Презентация может содержать один или более треков. \
[**tkhd**](#paramtkhd) *(track header)* — описаны характеристики одного трека *(timescale, длительность конкретного трека и т.д.)*. В одном треке может находится только один tkhd атом. \
[**mdia**](#parammdia) *(media)* — контейнер медиа описаний хранящий все объекты, которые имеют информацию о медиа данных принадлежащих треку. \
[**mdhd**](#parammdhd) *(media header)* — содержит параметры трека *(timescale, длительность конкретного трека и т.д.)*. \
[**hdlr**](#paramhdlr) *(handler reference)* — описывает процесс проигрывания медиа-данных трека. ***[копируем]*** \
[**minf**](#paramminf) *(media information)* — контейнер, хранящий один определенный media header, data information и sample table. \
[**vmhd**](#paramvmhd) *(video media header)* — содержит общую информацию о презентации видео данных. ***[копируем]*** \
[**dinf**](#paramdinf) *(data information)* — содержит объекты, которые объявляют место хранения медиа информации в треке. ***[копируем]*** \
[**dref**](#paramdref) *(data reference)* — содержит таблицу ссылок. Позволяет иметь треку одновременно несколько источников. ***[не используем]*** \
[**alis**](#paramalis) *(???)* — ???. ***[не используем]*** \
[**stbl**](#paramstbl) *(sample table)* — содержит таблицу с индексацией по времени и данным медиа сэмплов в треке. Используя находящиеся здесь таблицы можно определить их тип, размер, контейнер и оффсет *(смещение)* данных в mdat. \
[**stsc**](#paramstsc) *(sample to chunk)* — сэмплы внутри медиа данных сгруппированы в чанки. Чанки могут различный размер, и сэмплы внутри чанков тоже могут отличаться размером. Эта таблица может быть использована для поиска чанков, в которых хранятся сэмплы, их позицию и связанное с конкретным сэмплом описание. \
[**stts**](#paramstts) *(decoding time to sample)* — содержит компактную версию таблицы, которая позволяет проводить индексацию по дельте и количеству сэмплов. \
[**stsd**](#paramstsd) *(sample description)* — дает подробное описание типа использованного кодирования и информацию об инициализации необходимой для данной кодировки. ***[копируем]*** \
[**avc1**](#paramavc1) *(AVC)* — обозначает совместимость с расширениями AVC. ***[не используем]*** \
[**avcC**](#paramavcC) *(???)* — ??? ***[не используем]*** \
[**stss**](#paramstss) *(sync sample)* — хранит ключевые кадры. \
[**stco**](#paramstco) *(chunk offset)* — хранит сдвиг каждого чанка относительно начала файла. Существует два типа оффсетов: 32 битный и 64 битный. \
[**stsz**](#paramstsz) *(sample size)* — содержит число сэмплов и таблицу с размерами каждого сэмпла в байтах.

#### Для аудио

[**trak**](#paramtrak) *(«—»)* — «—». \
[**tkhd**](#paramtkhd) *(«—»)* — «—». \
[**mdia**](#parammdia) *(«—»)* — «—». \
[**mdhd**](#parammdhd) *(«—»)* — «—». \
[**hdlr**](#paramhdlr) *(«—»)* — «—». ***[копируем]*** \
[**minf**](#paramminf) *(«—»)* — «—». \
[**smhd**](#paramsmhd) *(sound media header)* — содержит общую информацию об аудио данных. ***[копируем]*** \
[**dinf**](#paramdinf) *(«—»)* — «—». ***[копируем]*** \
[**dref**](#paramdref) *(«—»)* — «—». ***[не используем]*** \
[**url** ](#paramurl) *(url)* — ссылка на местоположение медиа-данных используемых в презентации. ***[не используем]*** \
[**stbl**](#paramstbl) *(«—»)* — «—». \
[**stsd**](#paramstsd) *(«—»)* — «—». ***[копируем]*** \
[**mp4a**](#parammp4a) *(mp4)* — обозначает, что файл имеет незащищенный формат. \
**esds** *(???)* — ??? \
[**stts**](#paramstts) *(«—»)* — «—». \
[**stsc**](#paramstsc) *(«—»)* — «—». \
[**stsz**](#paramstsz) *(«—»)* — «—». \
[**stco**](#paramstco) *(«—»)* — «—».

#### Параметры

<a name="paramftyp"></a>
**ftyp**
-	Start offset
-	Box size
-	Box type

<a name="parammdat"></a>
**mdat**
-	Start offset
-	Box size
-	Box type
-	**Samples**
	-	No.
	-	Sample delta
	-	Size
	-	Chunk num
	-	Chunk offset
	-	i-Frame
	-	Sample offset

<a name="parammoov"></a>
**moov**
-	Start offset
-	Box size
-	Box type

<a name="parammvhd"></a>
**mvhd**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Creation time *(UTC)*
-	Modification time *(UTC)*
-	Time scale
-	Duration
-	Duration *(ms)*
-	Next track id
-	Volume
-	Rate

<a name="paramtrak"></a>
**trak**
-	Start offset
-	Box size
-	Box type

<a name="paramtkhd"></a>
**tkhd**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Creation time *(UTC)*
-	Modification time *(UTC)*
-	Track id
-	Duration
-	Width
-	Height

<a name="parammdia"></a>
**mdia**
-	Start offset
-	Box size
-	Box type

<a name="parammdhd"></a>
**mdhd**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Creation time *(UTC)*
-	Modification time *(UTC)*
-	Time scale
-	Duration
-	Language

<a name="paramhdlr"></a>
**hdlr**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Handler type
-	Name

<a name="paramminf"></a>
**minf**
-	Start offset
-	Box size
-	Box type

<a name="paramvmhd"></a>
**vmhd**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags

<a name="paramsmhd"></a>
**smhd**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags

<a name="paramdinf"></a>
**dinf**
-	Start offset
-	Box size
-	Box type

<a name="paramdref"></a>
**dref**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Enty count

<a name="paramalis"></a>
**alis**
-	Start offset
-	Box size
-	Box type

<a name="paramurl"></a>
**url**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Location

<a name="paramstbl"></a>
**stbl**
-	Start offset
-	Box size
-	Box type

<a name="paramstsc"></a>
**stsc**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Entry count
-	**List**
	-	No.
	-	First chunk
	-	Samples per chunk
	-	Samples description index

<a name="paramstts"></a>
**stts**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Entry count
-	**List**
	-	No.
	-	Sample count
	-	Sample delta

<a name="paramstsd"></a>
**stsd**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags

<a name="paramavc1"></a>
**avc1**
-	Start offset
-	Box size
-	Box type
-	Width
-	Height
-	Horiz resolution
-	Ver resolution
-	Compression name

<a name="paramavcC"></a>
**avcC**
-	Start offset
-	Box size
-	Box type
-	Configuration version
-	AVC profile indication
-	AVC profile compatibility
-	AVC level indication
-	NAL Unit length size
-	Num sequence parameter sets
-	Sequence parameter set (0)
-	Num picture parameter sets
-	Picture parameter set (0)

<a name="parammp4a"></a>
**mp4a**
-	Start offset
-	Box size
-	Box type

<a name="paramstss"></a>
**stss**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Entry count
-	**List**
	-	No.
	-	Sample number

<a name="paramstco"></a>
**stco**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Entry count
-	**List**
	-	No.
	-	Chunk offset

<a name="paramstsz"></a>
**stsz**
-	Start offset
-	Box size
-	Box type
-	Version
-	Flags
-	Sample size
-	Sample count
-	**List**
	-	No.
	-	Sample size