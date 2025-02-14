#pragma once
#include "../../basetypes.h"
#include "MineBlocksResult.h"
#include <retesteth/dataObject/DataObject.h>

using namespace dataobject;

namespace test
{
namespace teststruct
{
// Structure for RPC response test_rawTransaction
struct TestRawTransaction : MineBlocksResult
{
    TestRawTransaction(DataObject const&);
    FH20 const& sender() const { return m_sender; }
    FH32 const& trhash() const { return m_trHash; }
    string const& error() const;

private:
    spFH20 m_sender;
    spFH32 m_trHash;
};

}  // namespace teststruct
}  // namespace test
