/**
 * RCOS-EasyContact
 * EasyContact/Backend/ContactSystem
 * Triple.h
 * Copyright [2021] <RCOS-EasyContact>
 */
#ifndef BACKEND_CONTACTSYSTEM_TRIPLE_H_
#define BACKEND_CONTACTSYSTEM_TRIPLE_H_
/**
 * EasyContact Custom Namespace
 * BCS : Backend Contact System
 */
namespace BCS {
/**
 * Template Class
 * <Triple> Repersents
 * A Storage For Three Elements
 */
template <class A, class B, class C> class Triple {
 public:
  A first;
  B second;
  C third;
  Triple<A, B, C>(const A &ArgA, const B &ArgB, const C &ArgC)
      : first(ArgA), second(ArgB), third(ArgC) {}
};
}  // namespace BCS
#endif  // BACKEND_CONTACTSYSTEM_TRIPLE_H_
