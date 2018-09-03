#pragma once

#include <string>
#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <stdint.h>
#include <vector>
#include <macros.h>

#define MAX_BONES 100

// Contains the translation, rotation and scale of a single bone.
struct Keyframe
{
	glm::vec3 translation;
	glm::quat rotation;
	glm::vec3 scale;
};

// Contains the list of keyframes belonging to a particular bone.
struct AnimationChannel
{
	std::string			  joint_name;
	std::vector<Keyframe> keyframes;
};

// A structure containing Keyframes for each bone at the current point in time of the current animation.
struct Pose
{
	Keyframe keyframes[MAX_BONES];
};

// A list of 4x4 matrices representing the finalized transforms of each bone.
struct PoseTransforms
{
	DW_ALIGNED(16) glm::mat4 transforms[MAX_BONES];
};

class Skeleton;

// Contains an array of Channels.
struct Animation
{
	static Animation* load(const std::string& name, Skeleton* skeleton);

	std::string					  name;
	uint32_t					  keyframe_count;
	std::vector<AnimationChannel> channels;
	double						  duration;
};