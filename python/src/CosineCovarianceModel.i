// SWIG file CosineCovarianceModel.i

%{
#include "otcos/CosineCovarianceModel.hxx"
%}

%include CosineCovarianceModel_doc.i

%include otcos/CosineCovarianceModel.hxx
namespace OTCOS { %extend CosineCovarianceModel { CosineCovarianceModel(const CosineCovarianceModel & other) { return new OTCOS::CosineCovarianceModel(other); } } }
