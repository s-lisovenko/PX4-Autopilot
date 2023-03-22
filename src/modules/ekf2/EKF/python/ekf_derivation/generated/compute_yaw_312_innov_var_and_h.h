// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     backends/cpp/templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: compute_yaw_312_innov_var_and_h
 *
 * Args:
 *     state: Matrix24_1
 *     P: Matrix24_24
 *     R: Scalar
 *     epsilon: Scalar
 *
 * Outputs:
 *     innov_var: Scalar
 *     H: Matrix24_1
 */
template <typename Scalar>
void ComputeYaw312InnovVarAndH(const matrix::Matrix<Scalar, 24, 1>& state,
                               const matrix::Matrix<Scalar, 24, 24>& P, const Scalar R,
                               const Scalar epsilon, Scalar* const innov_var = nullptr,
                               matrix::Matrix<Scalar, 24, 1>* const H = nullptr) {
  // Total ops: 73

  // Input arrays

  // Intermediate terms (15)
  const Scalar _tmp0 = 2 * state(0, 0);
  const Scalar _tmp1 = 2 * state(2, 0);
  const Scalar _tmp2 = -_tmp0 * state(3, 0) + _tmp1 * state(1, 0);
  const Scalar _tmp3 =
      -2 * std::pow(state(1, 0), Scalar(2)) - 2 * std::pow(state(3, 0), Scalar(2)) + 1;
  const Scalar _tmp4 = _tmp3 + epsilon * ((((_tmp3) > 0) - ((_tmp3) < 0)) + Scalar(0.5));
  const Scalar _tmp5 = std::pow(_tmp4, Scalar(2));
  const Scalar _tmp6 = 4 * _tmp2 / _tmp5;
  const Scalar _tmp7 = Scalar(1.0) / (_tmp4);
  const Scalar _tmp8 = Scalar(1.0) / (std::pow(_tmp2, Scalar(2)) + _tmp5);
  const Scalar _tmp9 = _tmp5 * _tmp8;
  const Scalar _tmp10 = _tmp9 * (-_tmp1 * _tmp7 - _tmp6 * state(1, 0));
  const Scalar _tmp11 = _tmp9 * (_tmp0 * _tmp7 - _tmp6 * state(3, 0));
  const Scalar _tmp12 = 2 * _tmp4 * _tmp8;
  const Scalar _tmp13 = _tmp12 * state(3, 0);
  const Scalar _tmp14 = _tmp12 * state(1, 0);

  // Output terms (2)
  if (innov_var != nullptr) {
    Scalar& _innov_var = (*innov_var);

    _innov_var =
        R + _tmp10 * (P(0, 1) * _tmp13 + P(1, 1) * _tmp10 - P(2, 1) * _tmp14 + P(3, 1) * _tmp11) +
        _tmp11 * (P(0, 3) * _tmp13 + P(1, 3) * _tmp10 - P(2, 3) * _tmp14 + P(3, 3) * _tmp11) +
        _tmp13 * (P(0, 0) * _tmp13 + P(1, 0) * _tmp10 - P(2, 0) * _tmp14 + P(3, 0) * _tmp11) -
        _tmp14 * (P(0, 2) * _tmp13 + P(1, 2) * _tmp10 - P(2, 2) * _tmp14 + P(3, 2) * _tmp11);
  }

  if (H != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _h = (*H);

    _h.setZero();

    _h(0, 0) = _tmp13;
    _h(1, 0) = _tmp10;
    _h(2, 0) = -_tmp14;
    _h(3, 0) = _tmp11;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
