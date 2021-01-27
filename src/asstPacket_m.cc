//
// Generated file, do not edit! Created by nedtool 5.6 from asstPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "asstPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace asst_rtt_caso3 {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(AsstPacket)

AsstPacket::AsstPacket(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->numHops = 0;
    this->sourceTime = 0;
    this->sinkTime = 0;
    nodes_arraysize = 0;
    this->nodes = 0;
    relleno_arraysize = 0;
    this->relleno = 0;
}

AsstPacket::AsstPacket(const AsstPacket& other) : ::omnetpp::cPacket(other)
{
    nodes_arraysize = 0;
    this->nodes = 0;
    relleno_arraysize = 0;
    this->relleno = 0;
    copy(other);
}

AsstPacket::~AsstPacket()
{
    delete [] this->nodes;
    delete [] this->relleno;
}

AsstPacket& AsstPacket::operator=(const AsstPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void AsstPacket::copy(const AsstPacket& other)
{
    this->numHops = other.numHops;
    this->source = other.source;
    this->sourceTime = other.sourceTime;
    this->sinkTime = other.sinkTime;
    delete [] this->nodes;
    this->nodes = (other.nodes_arraysize==0) ? nullptr : new int[other.nodes_arraysize];
    nodes_arraysize = other.nodes_arraysize;
    for (unsigned int i=0; i<nodes_arraysize; i++)
        this->nodes[i] = other.nodes[i];
    delete [] this->relleno;
    this->relleno = (other.relleno_arraysize==0) ? nullptr : new char[other.relleno_arraysize];
    relleno_arraysize = other.relleno_arraysize;
    for (unsigned int i=0; i<relleno_arraysize; i++)
        this->relleno[i] = other.relleno[i];
}

void AsstPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->numHops);
    doParsimPacking(b,this->source);
    doParsimPacking(b,this->sourceTime);
    doParsimPacking(b,this->sinkTime);
    b->pack(nodes_arraysize);
    doParsimArrayPacking(b,this->nodes,nodes_arraysize);
    b->pack(relleno_arraysize);
    doParsimArrayPacking(b,this->relleno,relleno_arraysize);
}

void AsstPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->numHops);
    doParsimUnpacking(b,this->source);
    doParsimUnpacking(b,this->sourceTime);
    doParsimUnpacking(b,this->sinkTime);
    delete [] this->nodes;
    b->unpack(nodes_arraysize);
    if (nodes_arraysize==0) {
        this->nodes = 0;
    } else {
        this->nodes = new int[nodes_arraysize];
        doParsimArrayUnpacking(b,this->nodes,nodes_arraysize);
    }
    delete [] this->relleno;
    b->unpack(relleno_arraysize);
    if (relleno_arraysize==0) {
        this->relleno = 0;
    } else {
        this->relleno = new char[relleno_arraysize];
        doParsimArrayUnpacking(b,this->relleno,relleno_arraysize);
    }
}

int AsstPacket::getNumHops() const
{
    return this->numHops;
}

void AsstPacket::setNumHops(int numHops)
{
    this->numHops = numHops;
}

const char * AsstPacket::getSource() const
{
    return this->source.c_str();
}

void AsstPacket::setSource(const char * source)
{
    this->source = source;
}

double AsstPacket::getSourceTime() const
{
    return this->sourceTime;
}

void AsstPacket::setSourceTime(double sourceTime)
{
    this->sourceTime = sourceTime;
}

double AsstPacket::getSinkTime() const
{
    return this->sinkTime;
}

void AsstPacket::setSinkTime(double sinkTime)
{
    this->sinkTime = sinkTime;
}

void AsstPacket::setNodesArraySize(unsigned int size)
{
    int *nodes2 = (size==0) ? nullptr : new int[size];
    unsigned int sz = nodes_arraysize < size ? nodes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        nodes2[i] = this->nodes[i];
    for (unsigned int i=sz; i<size; i++)
        nodes2[i] = 0;
    nodes_arraysize = size;
    delete [] this->nodes;
    this->nodes = nodes2;
}

unsigned int AsstPacket::getNodesArraySize() const
{
    return nodes_arraysize;
}

int AsstPacket::getNodes(unsigned int k) const
{
    if (k>=nodes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", nodes_arraysize, k);
    return this->nodes[k];
}

void AsstPacket::setNodes(unsigned int k, int nodes)
{
    if (k>=nodes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", nodes_arraysize, k);
    this->nodes[k] = nodes;
}

void AsstPacket::setRellenoArraySize(unsigned int size)
{
    char *relleno2 = (size==0) ? nullptr : new char[size];
    unsigned int sz = relleno_arraysize < size ? relleno_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        relleno2[i] = this->relleno[i];
    for (unsigned int i=sz; i<size; i++)
        relleno2[i] = 0;
    relleno_arraysize = size;
    delete [] this->relleno;
    this->relleno = relleno2;
}

unsigned int AsstPacket::getRellenoArraySize() const
{
    return relleno_arraysize;
}

char AsstPacket::getRelleno(unsigned int k) const
{
    if (k>=relleno_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", relleno_arraysize, k);
    return this->relleno[k];
}

void AsstPacket::setRelleno(unsigned int k, char relleno)
{
    if (k>=relleno_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", relleno_arraysize, k);
    this->relleno[k] = relleno;
}

class AsstPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AsstPacketDescriptor();
    virtual ~AsstPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AsstPacketDescriptor)

AsstPacketDescriptor::AsstPacketDescriptor() : omnetpp::cClassDescriptor("asst_rtt_caso3::AsstPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

AsstPacketDescriptor::~AsstPacketDescriptor()
{
    delete[] propertynames;
}

bool AsstPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AsstPacket *>(obj)!=nullptr;
}

const char **AsstPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AsstPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AsstPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int AsstPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *AsstPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "numHops",
        "source",
        "sourceTime",
        "sinkTime",
        "nodes",
        "relleno",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int AsstPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numHops")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceTime")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sinkTime")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodes")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "relleno")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AsstPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "double",
        "double",
        "int",
        "char",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **AsstPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AsstPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AsstPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AsstPacket *pp = (AsstPacket *)object; (void)pp;
    switch (field) {
        case 4: return pp->getNodesArraySize();
        case 5: return pp->getRellenoArraySize();
        default: return 0;
    }
}

const char *AsstPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AsstPacket *pp = (AsstPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AsstPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AsstPacket *pp = (AsstPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getNumHops());
        case 1: return oppstring2string(pp->getSource());
        case 2: return double2string(pp->getSourceTime());
        case 3: return double2string(pp->getSinkTime());
        case 4: return long2string(pp->getNodes(i));
        case 5: return long2string(pp->getRelleno(i));
        default: return "";
    }
}

bool AsstPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AsstPacket *pp = (AsstPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setNumHops(string2long(value)); return true;
        case 1: pp->setSource((value)); return true;
        case 2: pp->setSourceTime(string2double(value)); return true;
        case 3: pp->setSinkTime(string2double(value)); return true;
        case 4: pp->setNodes(i,string2long(value)); return true;
        case 5: pp->setRelleno(i,string2long(value)); return true;
        default: return false;
    }
}

const char *AsstPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *AsstPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AsstPacket *pp = (AsstPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace asst_rtt_caso3

