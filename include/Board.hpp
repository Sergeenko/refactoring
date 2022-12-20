#pragma once

#include <vector>
#include "Squares.hpp"
#include <memory>

struct Board
{
    std::vector<std::shared_ptr<ISquare>> m_squares{
        std::make_unique<StartSquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<PenaltySquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>(),
        std::make_unique<RewardSquare>()};
};