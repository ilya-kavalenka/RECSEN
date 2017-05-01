protocol Protocol
{
    enum Enum; 

    set Set;   

    group Group;

    message Message1
    {
        bool Field1;
        char Field2;
        uchar Field3;
        int8 Field4;
        uint8 Field5;
        int16 Field6;
        uint16 Field7;
        int32 Field8;
        uint32 Field9;
        int64 Field10;
        uint64 Field11;
        double Field12;
        string Field13;
        ustring Field14;
        timestamp Field15;
        bytes Field16;
        Enum Field17;
        Set Field18;
        Group Field19;
    }

    message Message2
    {
        bool? Field1;
        char? Field2;
        uchar? Field3;
        int8? Field4;
        uint8? Field5;
        int16? Field6;
        uint16? Field7;
        int32? Field8;
        uint32? Field9;
        int64? Field10;
        uint64? Field11;
        double? Field12;
        string? Field13;
        ustring? Field14;
        timestamp? Field15;
        bytes? Field16;
        Enum? Field17;
        Set? Field18;
    }

    message Message3
    {
        bool[] Field1;
        char[] Field2;
        uchar[] Field3;
        int8[] Field4;
        uint8[] Field5;
        int16[] Field6;
        uint16[] Field7;
        int32[] Field8;
        uint32[] Field9;
        int64[] Field10;
        uint64[] Field11;
        double[] Field12;
        string[] Field13;
        ustring[] Field14;
        timestamp[] Field15;
        bytes[] Field16;
        Enum[] Field17;
        Set[] Field18;
        Group[] Field19;
    }

    message Message4
    {
        bool?[] Field1;
        char?[] Field2;
        uchar?[] Field3;
        int8?[] Field4;
        uint8?[] Field5;
        int16?[] Field6;
        uint16?[] Field7;
        int32?[] Field8;
        uint32?[] Field9;
        int64?[] Field10;
        uint64?[] Field11;
        double?[] Field12;
        string?[] Field13;
        ustring?[] Field14;
        timestamp?[] Field15;
        bytes?[] Field16;
        Enum?[] Field17;
        Set?[] Field18;
    }
}