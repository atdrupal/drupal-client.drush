drupal-client.drush
===================

### Install
 
mkdir ~/.drush
git clone http://git.io/1tV3bA ~/.drush/drush_client
 
### Usage

drush dget node/1 --uid=123
drush dpost admin/config/system/site-information '{"site_name": "Drupal"}'
