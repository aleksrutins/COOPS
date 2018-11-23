// #define var void*
// typedef struct {
// 	var value;
// } COOPSReference;
// COOPSReference createReferenceFor(var thingy) {
// 	COOPSReference ref;
// 	ref.value = thingy;
// 	return ref;
// }
// void *dereference(COOPSReference ref) {
// 	return ref.value;
// }
// #define namespace(name) struct {
// #define endNamespace(name) } name;
// #define expectClass(name) COOPSReference name;
// #define class(uid) struct uid {
// #define endClass(uid, name) } *__Cls__##uid##;\
// name = createReferenceFor(__Cls__##uid##);\
// typedef struct uid uid;
// #define expectMethod(retType, name, params) retType##(*name)params;
// #define method(classUid, retType, name, params, uid) retType uid##(params) {
// #define endMethod(classUid, name, uid) };\
// __Cls__##classUid##.##name = uid;
// #define initializable(classUid) method(classUid, classUid *, __init__, (), __init____##classUid##__)\
// 	classUid *__inst__;\
// 	__inst__ = __Cls__##classUid##;\
// 	return __inst__;\
// endMethod(classUid, init, __init____##classUid##__)
// #define init(className) __Cls__##className->init()
// I'll try to get that part working sometime...
#define var void*
#define class(name) struct __type__##name##__ {
#define endClass(name) } name;\
					   typedef struct __type__##name##__ __type__##name##__;
#define expectMethod(retType, name, params) retType(*name)params;
#define method(cls, retType, name, params) retType ___##cls##__##name##___ params {
#define endMethod(cls, name) };\
							 cls.name = ___##cls##__##name##___;
// #define initializable(cls) method(__type__##cls##__ *, ___##cls##_____init__, ())\
// 						   __type__##cls##__ inst = cls;\
// 						   return &inst;\
// 						   endMethod(___##cls##_____init__, cls.__init__)
// #define expectInitializable(cls) expectMethod(__type__##cls##__ *, __init__, ())
#define init(cls) cls.__init__()
#define classType(cls) __type__##cls##__