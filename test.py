import roslib
roslib.load_manifest('boost_serialization_example')
import boost_serialization_example as bse

S = bse.Serializer()

S.save()
S.load()
