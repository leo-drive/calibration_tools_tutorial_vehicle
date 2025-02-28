// Copyright 2023 Tier IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef EXTRINSIC_MAPPING_BASED_CALIBRATOR__FILTERS__BEST_FRAMES_FILTER_HPP_
#define EXTRINSIC_MAPPING_BASED_CALIBRATOR__FILTERS__BEST_FRAMES_FILTER_HPP_

#include <extrinsic_mapping_based_calibrator/filters/filter.hpp>
#include <extrinsic_mapping_based_calibrator/types.hpp>

#include <memory>
#include <string>
#include <vector>

class BestFramesFilter : public Filter
{
public:
  BestFramesFilter(const Filter::FilterType & filter_type, CalibrationParameters::Ptr & parameters)
  : Filter(filter_type, parameters)
  {
    name_ = "BestFramesFilter";
  }
  BestFramesFilter(
    const Filter::FilterType & filter_type, const std::string & name,
    const CalibrationParameters::Ptr & parameters)
  : Filter(filter_type, parameters)
  {
    setName(name);
  }
  virtual ~BestFramesFilter() {}

  std::vector<CalibrationFrame> filter(
    const std::vector<CalibrationFrame> & calibration_frames,
    MappingData::Ptr & mapping_data) override;
  void setName(const std::string & name) override;
};

#endif  // EXTRINSIC_MAPPING_BASED_CALIBRATOR__FILTERS__BEST_FRAMES_FILTER_HPP_
