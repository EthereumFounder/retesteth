#pragma once
#include "../../basetypes.h"
#include <retesteth/dataObject/DataObject.h>

using namespace dataobject;

namespace test
{
namespace teststruct
{
/*
 * VMTrace: (stExample/add11, fork: Istanbul, TrInfo: d: 0, g: 0, v: 0)
Transaction number: 0, hash: 0x5363f287fccaad86a0ce8d2c5b15b4b917afe6ebac6a87e61884bf18fc7af58a
{"pc":0,"op":96,"gas":"0x5c878","gasCost":"0x3","memory":"0x","memSize":0,
 "stack":[],"returnStack":[],"returnData":null,"depth":1,"refund":0,"opName":"PUSH1","error":""}
*/

struct VMLogRecord
{
    VMLogRecord(DataObject const&);
    size_t pc;
    size_t op;
    spVALUE gas;
    spVALUE gasCost;
    spBYTES memory;
    long long memSize;
    std::vector<string> stack;
    spBYTES returnData;
    size_t depth;
    spVALUE refund;
    string opName;
    string error;
};

struct DebugVMTrace
{
    DebugVMTrace() {}  // for tuples
    DebugVMTrace(string const& _info, string const& _trNumber, FH32 const& _trHash, string const& _logs);
    void print();
    void printNice();

private:
    string m_infoString;
    string m_trNumber;
    spFH32 m_trHash;
    std::vector<VMLogRecord> m_log;
    string m_rawUnparsedLogs;

    // Last record
    string m_output;
    spVALUE m_gasUsed;
    long long m_time;
};


}  // namespace teststruct
}  // namespace test
