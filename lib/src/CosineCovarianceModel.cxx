//                                               -*- C++ -*-
/**
 *
 *  Copyright 2005-2020 Airbus-EDF-IMACS-ONERA-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "otcos/CosineCovarianceModel.hxx"
#include "openturns/PersistentObjectFactory.hxx"
#include "openturns/Exception.hxx"
#include "openturns/SpecFunc.hxx"

using namespace OT;

namespace OTCOS {

CLASSNAMEINIT(CosineCovarianceModel)

static const Factory<CosineCovarianceModel> Factory_CosineCovarianceModel;


/* Default constructor */
CosineCovarianceModel::CosineCovarianceModel()
  : StationaryCovarianceModel(Point(1, 1.0), Point(1, 1.0))
  , alpha_(1.0)
{
  definesComputeStandardRepresentative_ = true;
}

/** Parameters constructor */
CosineCovarianceModel::CosineCovarianceModel(const Point & scale,
               const Point & amplitude,
               const Scalar alpha)
  : StationaryCovarianceModel(scale, amplitude)
  , alpha_(alpha)
{
  if (!(alpha > 0.0))
    throw InvalidArgumentException(HERE) << "Alpha coefficient must be positive";
  if (getInputDimension() != 1)
    throw InvalidArgumentException(HERE) << "In CosineCovarianceModel::CosineCovarianceModel, only unidimensional models should be defined."
                                         << " Here, (got inputDimension=" << getInputDimension() << ")";
  if (getOutputDimension() != 1)
    throw InvalidArgumentException(HERE) << "In CosineCovarianceModel::CosineCovarianceModel, only unidimensional models should be defined."
                                         << " Here, (got dimension=" << getOutputDimension() << ")";
  definesComputeStandardRepresentative_ = true;
}

/* Virtual constructor */
CosineCovarianceModel * CosineCovarianceModel::clone() const
{
  return new CosineCovarianceModel(*this);
}

/* Computation of the covariance function */
Scalar CosineCovarianceModel::computeStandardRepresentative(const Point & tau) const
{
  if (tau.getDimension() != inputDimension_) throw InvalidArgumentException(HERE) << "Error: expected a shift of dimension=" << inputDimension_ << ", got dimension=" << tau.getDimension();

  return computeStandardRepresentative(tau.begin(), tau.end());
}

Scalar CosineCovarianceModel::computeStandardRepresentative(const Collection<Scalar>::const_iterator & s_begin,
    const Collection<Scalar>::const_iterator & t_begin) const
{
  Scalar tauOverThetaNorm = std::abs(*s_begin - *t_begin) / scale_[0];
  // 2-pi periodicity
  tauOverThetaNorm -= floor(tauOverThetaNorm / (2.0 * M_PI)) * (2.0 * M_PI);
  return cos(4.0 * tauOverThetaNorm) * cosh((tauOverThetaNorm - M_PI) / alpha_) / cosh(M_PI / alpha_);
}

/* String converter */
String CosineCovarianceModel::__repr__() const
{
  OSS oss;
  oss << "class=" << CosineCovarianceModel::GetClassName()
      << " scale=" << scale_
      << " amplitude=" << amplitude_
      << " alpha=" << alpha_;
  return oss;
}

/* String converter */
String CosineCovarianceModel::__str__(const String & ) const
{
  OSS oss;
  oss << CosineCovarianceModel::GetClassName()
      << "(scale=" << scale_.__str__()
      << ", amplitude=" << amplitude_.__str__()
      << ", alpha=" << alpha_
      << ")";
  return oss;
}

/* Method save() stores the object through the StorageManager */
void CosineCovarianceModel::save(Advocate & adv) const
{
  StationaryCovarianceModel::save(adv);
  adv.saveAttribute( "alpha_", alpha_);
}

/* Method load() reloads the object from the StorageManager */
void CosineCovarianceModel::load(Advocate & adv)
{
  StationaryCovarianceModel::load(adv);
  adv.loadAttribute( "alpha_", alpha_);
}

}
