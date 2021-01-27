//
// Generated file, do not edit! Created by nedtool 5.6 from asstPacket.msg.
//

#ifndef __ASST_RTT_CASO3_ASSTPACKET_M_H
#define __ASST_RTT_CASO3_ASSTPACKET_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace asst_rtt_caso3 {

/**
 * Class generated from <tt>asstPacket.msg:11</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * packet AsstPacket
 * {
 *     int numHops;
 *     string source;
 *     double sourceTime;
 *     double sinkTime;
 *     int nodes[];
 *     char relleno[]; // 1byte por char
 * }
 * </pre>
 */
class AsstPacket : public ::omnetpp::cPacket
{
  protected:
    int numHops;
    ::omnetpp::opp_string source;
    double sourceTime;
    double sinkTime;
    int *nodes; // array ptr
    unsigned int nodes_arraysize;
    char *relleno; // array ptr
    unsigned int relleno_arraysize;

  private:
    void copy(const AsstPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const AsstPacket&);

  public:
    AsstPacket(const char *name=nullptr, short kind=0);
    AsstPacket(const AsstPacket& other);
    virtual ~AsstPacket();
    AsstPacket& operator=(const AsstPacket& other);
    virtual AsstPacket *dup() const override {return new AsstPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getNumHops() const;
    virtual void setNumHops(int numHops);
    virtual const char * getSource() const;
    virtual void setSource(const char * source);
    virtual double getSourceTime() const;
    virtual void setSourceTime(double sourceTime);
    virtual double getSinkTime() const;
    virtual void setSinkTime(double sinkTime);
    virtual void setNodesArraySize(unsigned int size);
    virtual unsigned int getNodesArraySize() const;
    virtual int getNodes(unsigned int k) const;
    virtual void setNodes(unsigned int k, int nodes);
    virtual void setRellenoArraySize(unsigned int size);
    virtual unsigned int getRellenoArraySize() const;
    virtual char getRelleno(unsigned int k) const;
    virtual void setRelleno(unsigned int k, char relleno);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const AsstPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, AsstPacket& obj) {obj.parsimUnpack(b);}

} // namespace asst_rtt_caso3

#endif // ifndef __ASST_RTT_CASO3_ASSTPACKET_M_H

