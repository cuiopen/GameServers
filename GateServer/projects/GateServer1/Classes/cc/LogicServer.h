// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: LogicServer.proto

#ifndef PROTOBUF_LogicServer_2eproto__INCLUDED
#define PROTOBUF_LogicServer_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_LogicServer_2eproto();
void protobuf_AssignDesc_LogicServer_2eproto();
void protobuf_ShutdownFile_LogicServer_2eproto();

class CLogicLogin;
class SLogicLogin;

// ===================================================================

class CLogicLogin : public ::google::protobuf::Message {
 public:
  CLogicLogin();
  virtual ~CLogicLogin();

  CLogicLogin(const CLogicLogin& from);

  inline CLogicLogin& operator=(const CLogicLogin& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CLogicLogin& default_instance();

  void Swap(CLogicLogin* other);

  // implements Message ----------------------------------------------

  CLogicLogin* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CLogicLogin& from);
  void MergeFrom(const CLogicLogin& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 cmd = 1 [default = 4096];
  inline bool has_cmd() const;
  inline void clear_cmd();
  static const int kCmdFieldNumber = 1;
  inline ::google::protobuf::uint32 cmd() const;
  inline void set_cmd(::google::protobuf::uint32 value);

  // optional string servername = 2;
  inline bool has_servername() const;
  inline void clear_servername();
  static const int kServernameFieldNumber = 2;
  inline const ::std::string& servername() const;
  inline void set_servername(const ::std::string& value);
  inline void set_servername(const char* value);
  inline void set_servername(const char* value, size_t size);
  inline ::std::string* mutable_servername();
  inline ::std::string* release_servername();
  inline void set_allocated_servername(::std::string* servername);

  // optional string seession = 3;
  inline bool has_seession() const;
  inline void clear_seession();
  static const int kSeessionFieldNumber = 3;
  inline const ::std::string& seession() const;
  inline void set_seession(const ::std::string& value);
  inline void set_seession(const char* value);
  inline void set_seession(const char* value, size_t size);
  inline ::std::string* mutable_seession();
  inline ::std::string* release_seession();
  inline void set_allocated_seession(::std::string* seession);

  // @@protoc_insertion_point(class_scope:protocol.CLogicLogin)
 private:
  inline void set_has_cmd();
  inline void clear_has_cmd();
  inline void set_has_servername();
  inline void clear_has_servername();
  inline void set_has_seession();
  inline void clear_has_seession();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* servername_;
  ::std::string* seession_;
  ::google::protobuf::uint32 cmd_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_LogicServer_2eproto();
  friend void protobuf_AssignDesc_LogicServer_2eproto();
  friend void protobuf_ShutdownFile_LogicServer_2eproto();

  void InitAsDefaultInstance();
  static CLogicLogin* default_instance_;
};
// -------------------------------------------------------------------

class SLogicLogin : public ::google::protobuf::Message {
 public:
  SLogicLogin();
  virtual ~SLogicLogin();

  SLogicLogin(const SLogicLogin& from);

  inline SLogicLogin& operator=(const SLogicLogin& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SLogicLogin& default_instance();

  void Swap(SLogicLogin* other);

  // implements Message ----------------------------------------------

  SLogicLogin* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SLogicLogin& from);
  void MergeFrom(const SLogicLogin& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 cmd = 1 [default = 4096];
  inline bool has_cmd() const;
  inline void clear_cmd();
  static const int kCmdFieldNumber = 1;
  inline ::google::protobuf::uint32 cmd() const;
  inline void set_cmd(::google::protobuf::uint32 value);

  // optional uint32 err = 2;
  inline bool has_err() const;
  inline void clear_err();
  static const int kErrFieldNumber = 2;
  inline ::google::protobuf::uint32 err() const;
  inline void set_err(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:protocol.SLogicLogin)
 private:
  inline void set_has_cmd();
  inline void clear_has_cmd();
  inline void set_has_err();
  inline void clear_has_err();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 cmd_;
  ::google::protobuf::uint32 err_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_LogicServer_2eproto();
  friend void protobuf_AssignDesc_LogicServer_2eproto();
  friend void protobuf_ShutdownFile_LogicServer_2eproto();

  void InitAsDefaultInstance();
  static SLogicLogin* default_instance_;
};
// ===================================================================


// ===================================================================

// CLogicLogin

// optional uint32 cmd = 1 [default = 4096];
inline bool CLogicLogin::has_cmd() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CLogicLogin::set_has_cmd() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CLogicLogin::clear_has_cmd() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CLogicLogin::clear_cmd() {
  cmd_ = 4096u;
  clear_has_cmd();
}
inline ::google::protobuf::uint32 CLogicLogin::cmd() const {
  return cmd_;
}
inline void CLogicLogin::set_cmd(::google::protobuf::uint32 value) {
  set_has_cmd();
  cmd_ = value;
}

// optional string servername = 2;
inline bool CLogicLogin::has_servername() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CLogicLogin::set_has_servername() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CLogicLogin::clear_has_servername() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CLogicLogin::clear_servername() {
  if (servername_ != &::google::protobuf::internal::kEmptyString) {
    servername_->clear();
  }
  clear_has_servername();
}
inline const ::std::string& CLogicLogin::servername() const {
  return *servername_;
}
inline void CLogicLogin::set_servername(const ::std::string& value) {
  set_has_servername();
  if (servername_ == &::google::protobuf::internal::kEmptyString) {
    servername_ = new ::std::string;
  }
  servername_->assign(value);
}
inline void CLogicLogin::set_servername(const char* value) {
  set_has_servername();
  if (servername_ == &::google::protobuf::internal::kEmptyString) {
    servername_ = new ::std::string;
  }
  servername_->assign(value);
}
inline void CLogicLogin::set_servername(const char* value, size_t size) {
  set_has_servername();
  if (servername_ == &::google::protobuf::internal::kEmptyString) {
    servername_ = new ::std::string;
  }
  servername_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CLogicLogin::mutable_servername() {
  set_has_servername();
  if (servername_ == &::google::protobuf::internal::kEmptyString) {
    servername_ = new ::std::string;
  }
  return servername_;
}
inline ::std::string* CLogicLogin::release_servername() {
  clear_has_servername();
  if (servername_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = servername_;
    servername_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CLogicLogin::set_allocated_servername(::std::string* servername) {
  if (servername_ != &::google::protobuf::internal::kEmptyString) {
    delete servername_;
  }
  if (servername) {
    set_has_servername();
    servername_ = servername;
  } else {
    clear_has_servername();
    servername_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional string seession = 3;
inline bool CLogicLogin::has_seession() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CLogicLogin::set_has_seession() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CLogicLogin::clear_has_seession() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CLogicLogin::clear_seession() {
  if (seession_ != &::google::protobuf::internal::kEmptyString) {
    seession_->clear();
  }
  clear_has_seession();
}
inline const ::std::string& CLogicLogin::seession() const {
  return *seession_;
}
inline void CLogicLogin::set_seession(const ::std::string& value) {
  set_has_seession();
  if (seession_ == &::google::protobuf::internal::kEmptyString) {
    seession_ = new ::std::string;
  }
  seession_->assign(value);
}
inline void CLogicLogin::set_seession(const char* value) {
  set_has_seession();
  if (seession_ == &::google::protobuf::internal::kEmptyString) {
    seession_ = new ::std::string;
  }
  seession_->assign(value);
}
inline void CLogicLogin::set_seession(const char* value, size_t size) {
  set_has_seession();
  if (seession_ == &::google::protobuf::internal::kEmptyString) {
    seession_ = new ::std::string;
  }
  seession_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CLogicLogin::mutable_seession() {
  set_has_seession();
  if (seession_ == &::google::protobuf::internal::kEmptyString) {
    seession_ = new ::std::string;
  }
  return seession_;
}
inline ::std::string* CLogicLogin::release_seession() {
  clear_has_seession();
  if (seession_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = seession_;
    seession_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void CLogicLogin::set_allocated_seession(::std::string* seession) {
  if (seession_ != &::google::protobuf::internal::kEmptyString) {
    delete seession_;
  }
  if (seession) {
    set_has_seession();
    seession_ = seession;
  } else {
    clear_has_seession();
    seession_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// SLogicLogin

// optional uint32 cmd = 1 [default = 4096];
inline bool SLogicLogin::has_cmd() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SLogicLogin::set_has_cmd() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SLogicLogin::clear_has_cmd() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SLogicLogin::clear_cmd() {
  cmd_ = 4096u;
  clear_has_cmd();
}
inline ::google::protobuf::uint32 SLogicLogin::cmd() const {
  return cmd_;
}
inline void SLogicLogin::set_cmd(::google::protobuf::uint32 value) {
  set_has_cmd();
  cmd_ = value;
}

// optional uint32 err = 2;
inline bool SLogicLogin::has_err() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SLogicLogin::set_has_err() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SLogicLogin::clear_has_err() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SLogicLogin::clear_err() {
  err_ = 0u;
  clear_has_err();
}
inline ::google::protobuf::uint32 SLogicLogin::err() const {
  return err_;
}
inline void SLogicLogin::set_err(::google::protobuf::uint32 value) {
  set_has_err();
  err_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_LogicServer_2eproto__INCLUDED